# High_Level_Utils

High_Level_Utils is a utility library that offers higher-level language features to C++. It provides functions like `eval`, `split`, and `AreParanthesesBalanced`, which allow you to manipulate strings, evaluate expressions, and check for balanced brackets. The library is still under development, so users should be cautious of potential bugs. More features will be added over time.

## Features

- **eval**: Evaluate mathematical expressions and return the result.
- **split**: Split a string based on a specified delimiter.
- **getSubstring**: Extract a substring from a given string between specified indices.
- **AreParanthesesBalanced**: Check if the parentheses in a string are balanced.

## Installation

### Clone from GitHub

To install High_Level_Utils using `git`:

```bash
git clone https://github.com/your-repo-url/High_Level_Utils.git
cd High_Level_Utils
```
### Download ZIP

Alternatively, you can download the repository as a ZIP file and extract it:

1. Go to the repository page.
2. Click on "Code" > "Download ZIP".
3. Extract the ZIP file and navigate to the extracted directory.

## Usage

Include the header file in your C++ project:

```cpp
#include "HighLevelUtilities.h"
```

### Example Usage

Here are examples of how to use some of the functions provided by the library:

1. eval: Evaluate a mathematical expression

```cpp
float result;
std::string expression = "3+4*(2-1)";  // NO SPACES
eval(expression, result);
std::cout << "Result: " << result << std::endl;
```
2. split: Split a string by a delimiter

```cpp
std::string data = "apple,banana,cherry";
std::vector<std::string> items = split(data, ',');
for (const auto& item : items) {
    std::cout << item << std::endl;
}
```

3. getSubstring: Get a substring from a given string

```cpp
std::string text = "Hello, World!";
std::string sub = getSubstring(text, 7, 12);
std::cout << "Substring: " << sub << std::endl;   // prints "World!"
```

4. AreParanthesesBalanced: Check if parentheses are balanced

```cpp
std::string exp = "()(())";
if (AreParanthesesBalanced(exp)) {
    std::cout << "Parentheses are balanced." << std::endl;    // exp is balanced
} else {
    std::cout << "Parentheses are not balanced." << std::endl;
}
```
