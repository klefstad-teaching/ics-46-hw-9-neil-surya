#include <vector>
#include <string>
#include <iostream>
#include <set>

void error(string word1, string word2, string msg) {
    cout << "Error with " << word1 << " and " << word2 << ": " << msg << endl;
}
bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_adjacent(const string& word1, const string& word2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    // initial edge checks
    if (begin_word == end_word) {
        error(begin_word, end_word, "Begin and end word are the same!");
        return {};
    } else if (word_list.find(end_word) == word_list.end()) {
        error(end_word, "", "End word not in the dictionary!");
        return {};
    }

    vector<string> curr;
    queue<vector<string>> partial;
    partial.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    // bfs time
    while (!partial.empty()) {
        curr = partial.front();
        partial.pop();
        string last = curr.back();

    }

    error(begin_word, end_word, "No valid word ladder found!");
    return {};
}
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();
