package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	n := 0
	k := 0
	fmt.Print("Введите количество кандидатов: ")
	fmt.Fscan(in, &n)
	fmt.Print("Введите количество вариантов ранжирования: ")
	fmt.Fscan(in, &k)
	candidates := readCandidates(in, n)
	ballots := readBallots(in, n, k)
	bordName, bordScore := bordWin(candidates, ballots)
	kondorse := kondorWin(candidates, ballots)
	printResult(bordName, bordScore, kondorse)
}

func bordWin(candidates []string, ballots [][]string) (string, int) {
	score := make(map[string]int)
	maxPoints := len(candidates) - 1
	for _, ballot := range ballots {
		points := maxPoints
		for _, candidate := range ballot {
			score[candidate] += points
			points--
		}
	}
	resultName := candidates[0]
	resultScore := score[candidates[0]]
	for _, candidate := range candidates {
		if score[candidate] > resultScore {
			resultName = candidate
			resultScore = score[candidate]
		}
	}
	return resultName, resultScore
}

func firstHigher(a string, b string, ranking []string) bool {
	isHigher := false
	isFound := false
	for _, candidate := range ranking {
		if !isFound && candidate == a {
			isHigher = true
			isFound = true
		}
		if !isFound && candidate == b {
			isHigher = false
			isFound = true
		}
	}
	return isHigher
}

func beatsInPair(a string, b string, ballots [][]string) bool {
	aVotes := 0
	bVotes := 0
	for _, ballot := range ballots {
		if firstHigher(a, b, ballot) {
			aVotes++
		} else {
			bVotes++
		}
	}
	return aVotes > bVotes
}

func kondorWin(candidates []string, ballots [][]string) string {
	result := "не определён"
	needWins := len(candidates) - 1
	for _, candidate := range candidates {
		wins := 0
		for _, opponent := range candidates {
			if candidate != opponent && beatsInPair(candidate, opponent, ballots) {
				wins++
			}
		}
		if result == "не определён" && wins == needWins {
			result = candidate
		}
	}
	return result
}

func readCandidates(in *bufio.Reader, n int) []string {
	candidates := make([]string, n)
	fmt.Println("Введите имена кандидатов:")
	for i := range candidates {
		fmt.Fscan(in, &candidates[i])
	}
	return candidates
}

func readBallots(in *bufio.Reader, n int, k int) [][]string {
	ballots := [][]string{}
	variants := make([][]string, k)
	fmt.Println("Введите количество избирателей и ранжирование:")
	for i := range variants {
		count := 0
		variants[i] = make([]string, n)
		fmt.Fscan(in, &count)
		for j := range variants[i] {
			fmt.Fscan(in, &variants[i][j])
		}
		sameBallots := make([][]string, count)
		for j := range sameBallots {
			sameBallots[j] = variants[i]
		}
		for _, ballot := range sameBallots {
			ballots = append(ballots, ballot)
		}
	}
	return ballots
}

func printResult(bordName string, bordScore int, kondorse string) {
	fmt.Printf("По Борду: %s (%d очков)\n", bordName, bordScore)
	fmt.Printf("По Кондорсе: %s\n", kondorse)
}
