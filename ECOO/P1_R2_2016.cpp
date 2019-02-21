#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int get_longest_palindrome(std::string string)
{
    int m = string.length();
    std::vector<int> indices(m);
    
    int length = 0;
    indices[0] = 0;
    
    int i = 1;
    while (i < m)
    {
        if(string[i] == string[length])
        {
            indices[i++] = ++length;
        }
        else
        {
            if(length!=0)
            {
                length = indices[length-1];
            }
            else
            {
                indices[i++] = 0;
            }
        }
    }
    
    return indices[indices.size() - 1];
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    for (int i = 0; i < 10; ++i)
    {
        std::string line;
        std::cin >> line;
        
        std::string reversed = line;
        std::reverse(reversed.begin(), reversed.end());
        
        int front = get_longest_palindrome(line + '#' + reversed);
        int back = get_longest_palindrome(reversed + '#' + line);
        std::cout << line.length() - std::max(front, back) << "\n";
    }
}