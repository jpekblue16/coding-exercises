#include <array>
#include <string>
#include <vector>
#include <iostream>

const int FAIL_SCORE = 40;

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    std::vector<int> roundedScores = {};

    for (const double& i : student_scores) {
        int score = static_cast<int>(i);
        roundedScores.insert(roundedScores.end(),score);
    }

    return roundedScores;
}


// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int failCount = 0;

    for (const int& score : student_scores) {
        if (score <= FAIL_SCORE) failCount++;
    }

    return failCount;
}

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
    // TODO: Implement above_threshold
    std::vector<int> aboveThreshold = {};

    for (const int& score : student_scores) {
        if (score >= threshold) aboveThreshold.insert(aboveThreshold.end(),score);
    }

    return aboveThreshold;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int scoreGap = highest_score - FAIL_SCORE;
    int interval = scoreGap / 4;
    // element 0 will always be 41

    std::array<int,4> lowestScoresPerLetterGrade  = {};

    for (int i = 0; i < 4; ++i) {
        lowestScoresPerLetterGrade[i] = 41 + i * interval;
    }

    return lowestScoresPerLetterGrade;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking

    std::vector<std::string> scores = {};

    for (auto i = 0; i < student_scores.size(); ++i) {

        std::string position = std::to_string(i+1);
        std::string score = std::to_string(student_scores[i]);
        std::string scoreString = position + ". "+student_names[i] + ": "+score;

        scores.insert(scores.end(),scoreString);
    }

    return scores;
}

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement perfect_score

    std::string perfectStudent = "";

    for (int i = 0; i < student_scores.size(); ++i) {

        std::cout << "student: " << student_names[i] << "; score: " << student_scores[i] << "\n";

        if (student_scores[i] == 100) {
            perfectStudent = student_names[i];
            break;
        }
    }

    return perfectStudent;
}
