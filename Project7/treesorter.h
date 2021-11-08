/*
 * treesorter.h
 * Aleks McCormick
 * 2021/11/08
 * Fall 2021 CS 311
 * SHORT DESCRIPTION
 */

#ifndef FALL2021_CS311_TREESORTER_H
#define FALL2021_CS311_TREESORTER_H

#include <iterator>
// For std::iterator_traits
#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
	// Value is the type that FDIter points to
	using Value = typename std::iterator_traits<FDIter>::value_type;

	// THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS, BUT IT DOES
	// NOT MEET THE REQUIREMENTS OF THE PROJECT.
	std::vector<Value> buff(std::distance(first, last));
	std::move(first, last, buff.begin());
	std::stable_sort(buff.begin(), buff.end());
	std::move(buff.begin(), buff.end(), first);
}

#endif //FALL2021_CS311_TREESORTER_H
