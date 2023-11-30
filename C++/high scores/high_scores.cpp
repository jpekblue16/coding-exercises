#include "high_scores.h"

#include <algorithm>

namespace arcade {

    std::vector<int> HighScores::list_scores() {
        // TODO: Return all scores for this session.
        return scores;
    }

    int HighScores::latest_score() {
        // TODO: Return the latest score for this session.
        return scores.back();
    }

    int HighScores::personal_best() {
        // TODO: Return the highest score for this session.
        return *(std::max_element(scores.begin(),scores.end()));
    }

    std::vector<int> HighScores::top_three() {
        // TODO: Return the top 3 scores for this session in descending order.

        if (scores.size() == 0) return scores;

        // if number of scores is <3, only create result vector of that size
        int returnSize = (scores.size() >= 3) ? 3 : scores.size();

        std::vector<int> result(returnSize);

        // use partial_sort_copy to find the top 3 (or returnSize) elements without modifying underlying vector
        std::partial_sort_copy(scores.begin(),scores.end(),result.begin(),result.end(),std::greater<>());

        return result;
    }

}  // namespace arcade
