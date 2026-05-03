package main

import "fmt"

func main() {
	a := 0
	b := 0
	m := 0
	count := 0
	operation := ""
	fmt.Print("Введите a, b, операцию ")
	fmt.Scan(&a, &b, &operation, &m)
	startValues := make([]int, max(a, b))
	fmt.Print("Введите нач знач ")
	for idx := range startValues {
		fmt.Scan(&startValues[idx])
	}
	fmt.Print("Введите кол ген чисел ")
	fmt.Scan(&count)
	result := Fibonachi(a, b, operation, m, startValues, count)
	printVector(result)
}

func calculateNextValue(first int, second int, operation string, m int) int {
	value := 0
	switch operation {
	case "+":
		value = first + second
	case "-":
		value = first - second
	case "*":
		value = first * second
	case "^":
		value = first ^ second
	}
	value %= m
	if value < 0 {
		value += m
	}
	return value
}

func Fibonachi(a int, b int, operation string, m int, sequence []int, count int) []int {
	result := make([]int, count)
	n := max(a, b)
	for idx := range result {
		result[idx] = calculateNextValue(sequence[n-a], sequence[n-b], operation, m)
		sequence = append(sequence, result[idx])
		n++
	}
	return result
}

func printVector(values []int) {
	for _, val := range values {
		fmt.Printf("%d ", val)
	}
}
