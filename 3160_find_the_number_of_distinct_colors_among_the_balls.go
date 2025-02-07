package main

import "fmt"

func queryResults(limit int, queries [][]int) []int {
	// use teo dictionaries of position color and color amount used
	var positionColour = make(map[int]int)
	var colourAmount = make(map[int]int)
	var different = 0
	var differences []int
	for i := 0; i < len(queries); i++ {
		colour, exists1 := positionColour[queries[i][0]] // get colour of position if it exists
		if colour != queries[i][1] {                     // if it is not the same as was before
			if exists1 { // if position already exist
				amount := colourAmount[colour]    // get amount of appearances of the old colour
				colourAmount[colour] = amount - 1 // decrease amount of appearances
				if amount == 1 {
					different--
				}
				amount, exists2 := colourAmount[queries[i][1]] // get amount of appearances of new colour
				if !exists2 || amount == 0 {                   // if colour does not
					colourAmount[queries[i][1]] = 0
					different++ // increase amount of new colours
				}
			} else { // if there is no such position
				// there could still be that c
				val, exists2 := colourAmount[queries[i][1]] // get amount of appearances of new colour
				if !exists2 || val == 0 {                   // if it does not exist or has 0 appearances
					colourAmount[queries[i][1]] = 0
					different++
				}
			}
			positionColour[queries[i][0]] = queries[i][1] // assign new colour to position
			colourAmount[queries[i][1]] += 1
		}

		differences = append(differences, different)

	}
	return differences
}

func main() {
	var limit int = 4
	var queries = [][]int{[]int{0, 1}, []int{0, 4}, []int{0, 4}, []int{0, 1}, []int{1, 2}}
	fmt.Println(queryResults(limit, queries))
	queries = [][]int{[]int{1, 4}, []int{2, 5}, []int{1, 3}, []int{3, 4}}
	fmt.Println(queryResults(limit, queries))

}
