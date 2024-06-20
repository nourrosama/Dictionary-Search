# Dictionary-Search
Trie, also known as a prefix tree, is an optimized data structure that excels
at storing and searching for strings. It offers efficient lookup and insertion
operations, making it ideal for tasks like searching for words or substrings within
a dataset. By organizing the dataset in a Trie structure, we can significantly
reduce the time complexity of our search operations, leading to faster and more
efficient implementations. (See Slides For More Clarification)
First of fall (Implementation of Trie Class):
- Insert
- Search
- Delete
- PrintAllWords
You should cover:
1. Single Word Search:
● Input: "apple"
● Description: User searches for a single word "apple" within the
dataset.
● Output: Word exist or not (True/False)
2. Multiple Words Search:
● Input: Input can consist of N Words.
● Input Example : N=3 Words = ["apple, application, apply"]
● Description: User searches for multiple words "apple",
"application", and "appply" within the dataset simultaneously (
at the same time in single search).
● Output: list of booleans where each word exists or not.
3. Partial Word Search(Prefix):
● Input: "appl"
● Description: User searches for words starting with the prefix
"appl", such as "apple", "appliance", etc.
● Output: list of all words starting with appl
4. Fuzzy Search:
● Input: "appl?"
● Description: User performs a fuzzy search, where '?' represents a
wildcard for a single character. This could match words like
"apple", "apply", "apples", etc.
● Output: list of words that starts with appl and ends with any
character.
5. Misspelled Word Search:
● Input: "aple"
● Description: User searches for a word with a potential
misspelling, expecting matches for words like "apple" despite the
spelling error.
● Output: list of similar words.
6. Partial Word Search(Suffix):
● Input: "ing"
● Description: User searches for words end with the suffix "ing",
such as "loading", "interesting", etc.
● Output: list of all words ends with ing.
7. Wildcard Search:
● Input: "c*t" OR *c*b OR *c*b* (You have to cover the three
test cases)
● Description: User searches for words matching the pattern "ct",
where '* represents any number of characters(0 or more).
This could match words like "cat", "coat", "cut", etc.
● Output: list of words that match the pattern
