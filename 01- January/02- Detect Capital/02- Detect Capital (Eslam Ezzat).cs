// Author: Eslam Ezzat

// Time Complexity: O(word.length)

// Space Complexity: O(1)

public class Solution
{
    public bool DetectCapitalUse(string word)
    {
        // First, get the size of string.
        // Making allCharCapital variable to count the uppercase letters.
        // Making allCharSMALL variable to count the lowercase letters.
        int sz = word.Length, allCharCapital = 0, allCharSmall = 0;

        // Iterate through the string to check if the char is upper or lower.
        for (int i = 0; i < sz; i++)
        {
            // char.IsUpper is used to check if the char is upper or not. 
            if (char.IsUpper(word[i]))
            {
                allCharCapital++; // Count uppercase letters.
            }
            else
            {
                allCharSmall++; // Count lowercase letters.
            }
        }

        //Check if all chars are capital or all chars are small or the first char is capital and the others are small.
        if (allCharCapital == sz || allCharSmall == sz ||
            (char.IsUpper(word[0]) && allCharSmall == sz - 1))
        {
            return true;
        }

        return false;
    }
};