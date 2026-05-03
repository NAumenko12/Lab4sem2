package main

import (
	"fmt"
	"math"
)

func main() {
	epsilon := 1e-4
	negativeRoots := solveRoot("ОТРИЦАТЕЛЬНЫЙ КОРЕНЬ", -2, -1.5, -2, false, epsilon)
	positiveRoots := solveRoot("ПОЛОЖИТЕЛЬНЫЙ КОРЕНЬ", 1.5, 2, 2, true, epsilon)
	fmt.Println("\nКорни по методу Ньютона:")
	fmt.Printf("x1 = %.10f\n", negativeRoots[1])
	fmt.Printf("x2 = %.10f\n", positiveRoots[1])
}

func f(x float64) float64 {
	return 2*x*x + math.Cos(x) - 6
}

func df(x float64) float64 {
	return 4*x - math.Sin(x)
}

func ddf(x float64) float64 {
	return 4 - math.Cos(x)
}

func phi(x float64, isPositive bool) float64 {
	result := math.Sqrt((6 - math.Cos(x)) / 2)
	if !isPositive {
		result = -result
	}
	return result
}

func printBisectionHeader(name string, a float64, b float64) {
	fmt.Printf("\n=== %s [%.1f, %.1f] ===\n", name, a, b)
	fmt.Printf("%-5s%-15s%-15s%-15s\n", "N", "a_n", "b_n", "b_n - a_n")
	fmt.Println("--------------------------------------------------")
}

func printIterHeader(name string, x0 float64) {
	fmt.Printf("\n=== %s (x0 = %.1f) ===\n", name, x0)
	fmt.Printf("%-5s%-15s%-15s%-15s\n", "N", "x_n", "x_n+1", "x_n+1 - x_n")
	fmt.Println("--------------------------------------------------")
}

func printRoot(root float64, n int) {
	fmt.Println("--------------------------------------------------")
	fmt.Printf("Корень найден: x = %.10f\n", root)
	fmt.Printf("f(x) = %.10f\n", f(root))
	fmt.Printf("Итераций: %d\n", n)
}

func bisectionMethod(a float64, b float64, epsilon float64) float64 {
	printBisectionHeader("Метод половинного деления", a, b)
	n := 0
	middle := (a + b) / 2
	for math.Abs(b-a) > epsilon {
		middle = (a + b) / 2
		fmt.Printf("%-5d%-15.6f%-15.6f%-15.6f\n", n, a, b, math.Abs(b-a))
		if f(a)*f(middle) < 0 {
			b = middle
		} else {
			a = middle
		}
		n++
	}
	middle = (a + b) / 2
	printRoot(middle, n)
	return middle
}

func newtonMethod(x0 float64, epsilon float64) float64 {
	printIterHeader("Метод Ньютона", x0)
	x := x0
	root := x0
	n := 0
	for diff := epsilon + 1; diff > epsilon; {
		nextX := x - f(x)/df(x)
		diff = math.Abs(nextX - x)
		fmt.Printf("%-5d%-15.6f%-15.6f%-15.6f\n", n, x, nextX, diff)
		root = nextX
		x = nextX
		n++
	}
	printRoot(root, n)
	return root
}

func simpleIterationMethod(x0 float64, epsilon float64, isPositive bool) float64 {
	printIterHeader("Метод простых итераций", x0)
	x := x0
	root := x0
	n := 0
	for diff := epsilon + 1; diff > epsilon; {
		nextX := phi(x, isPositive)
		diff = math.Abs(nextX - x)
		fmt.Printf("%-5d%-15.6f%-15.6f%-15.6f\n", n, x, nextX, diff)
		root = nextX
		x = nextX
		n++
	}
	printRoot(root, n)
	return root
}

func solveRoot(title string, a float64, b float64, x0 float64, isPositive bool, epsilon float64) []float64 {
	fmt.Printf("\n\n>>> %s <<<\n", title)
	fmt.Printf("Интервал отделения корня: [%.1f, %.1f]\n", a, b)
	fmt.Printf("Проверка знаков: f(a) = %.6f, f(b) = %.6f\n", f(a), f(b))
	fmt.Printf("Для Ньютона: f(x0) * f''(x0) = %.6f\n", f(x0)*ddf(x0))

	return []float64{
		bisectionMethod(a, b, epsilon),
		newtonMethod(x0, epsilon),
		simpleIterationMethod(x0, epsilon, isPositive),
	}
}
