package main

import (
	"fmt"
	"sort"
	"time"
)

func main() {
	gen := newRanlux24Base()
	n := 0
	fmt.Print("Введите n >= 10: ")
	fmt.Scan(&n)
	if n < 10 {
		fmt.Println("n должно быть не меньше 10.")
		return
	}
	arr := randomOfOneToFifth(n, &gen)
	fmt.Println("Пункт 1 массив инициализирован случайными числами 100-150")
	printArr(arr)
	secondMax, sumBetween := secondEllandSumEll(arr)
	fmt.Printf("\nВторой максимум: %d\n", secondMax)
	fmt.Printf("Сумма элементов между min и вторым max: %d\n", sumBetween)
	arr1, arr2, arr3 := thirdArrOfOneTwo(n, &gen)
	fmt.Println("1 массив (arr1):")
	printArr(arr1)
	fmt.Println("2 массив (arr2):")
	printArr(arr2)
	fmt.Println("3 массив (arr3, сумма/разность):")
	printArr(arr3)
	fmt.Println("\nПункт 4. Частота элементов первого массива:")
	uniqEllemets(arr)
	startYear := 0
	endYear := 0
	fmt.Print("Введите начальный год: ")
	fmt.Scan(&startYear)
	fmt.Print("Введите конечный год: ")
	fmt.Scan(&endYear)
	vesocYears := countVecosYear(startYear, endYear)
	if len(vesocYears) > 0 {
		fmt.Print("Високосные годы: ")
		printArr(vesocYears)
	} else {
		fmt.Println("Нет високосных годов в указанном диапазоне.")
	}
}

type Ranlux24Base struct {
	state [24]uint32
	index int
	carry uint32
}

func newRanlux24Base() Ranlux24Base {
	gen := Ranlux24Base{}
	seed := uint32(time.Now().UnixNano()%2147483646) + 1
	for idx := range gen.state {
		seed = uint32((uint64(seed) * 48271) % 2147483647)
		gen.state[idx] = seed & 0xffffff
	}
	return gen
}

func (gen *Ranlux24Base) next() int {
	j := gen.index - 10
	if j < 0 {
		j += 24
	}
	first := gen.state[j]
	second := gen.state[gen.index] + gen.carry
	if first >= second {
		gen.state[gen.index] = first - second
		gen.carry = 0
	} else {
		gen.state[gen.index] = (1 << 24) + first - second
		gen.carry = 1
	}
	value := gen.state[gen.index]
	gen.index++
	if gen.index == 24 {
		gen.index = 0
	}
	return int(value)
}

func fillRandom(arr []int, minVal int, maxVal int, gen *Ranlux24Base) {
	for idx := range arr {
		arr[idx] = minVal + gen.next()%(maxVal-minVal+1)
	}
}

func randomOfOneToFifth(n int, gen *Ranlux24Base) []int {
	arr := make([]int, n)
	fillRandom(arr, 100, 150, gen)
	return arr
}

func printArr(arr []int) {
	for _, val := range arr {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
}

func secondEllandSumEll(arr []int) (int, int) {
	sortedArr := append([]int{}, arr...)
	sort.Ints(sortedArr)
	minVal := sortedArr[0]
	secondMax := sortedArr[len(sortedArr)-2]
	minIdx := -1
	secondIdx := -1
	for idx, val := range arr {
		if minIdx == -1 && val == minVal {
			minIdx = idx
		}
		if secondIdx == -1 && val == secondMax && idx != minIdx {
			secondIdx = idx
		}
	}
	left := minIdx
	right := secondIdx
	if left > right {
		left, right = right, left
	}
	sumBetween := 0
	for idx, val := range arr {
		if idx > left && idx < right {
			sumBetween += val
		}
	}
	return secondMax, sumBetween
}

func thirdArrOfOneTwo(n int, gen *Ranlux24Base) ([]int, []int, []int) {
	arr1 := make([]int, n)
	arr2 := make([]int, n)
	arr3 := make([]int, n)
	fillRandom(arr1, -50, 50, gen)
	fillRandom(arr2, -50, 50, gen)
	for idx := range arr3 {
		if idx%2 == 0 {
			arr3[idx] = arr1[idx] + arr2[idx]
		} else {
			arr3[idx] = arr1[idx] - arr2[idx]
		}
	}
	return arr1, arr2, arr3
}

func uniqEllemets(arr []int) {
	freq := make(map[int]int)
	for _, val := range arr {
		freq[val]++
	}
	keys := make([]int, 0, len(freq))
	for val := range freq {
		keys = append(keys, val)
	}
	sort.Ints(keys)
	for _, val := range keys {
		fmt.Printf("%d встречается %d раз(а)\n", val, freq[val])
	}
}

func countVecosYear(startYear int, endYear int) []int {
	if startYear > endYear {
		startYear, endYear = endYear, startYear
	}
	vesoc := []int{}
	for year := startYear; year <= endYear; year++ {
		if year%400 == 0 || year%4 == 0 && year%100 != 0 {
			vesoc = append(vesoc, year)
		}
	}
	return vesoc
}
