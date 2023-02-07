//Author: Sara Hamza
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //approach : simulate the problem

        //already this is the max no we can get
        int n = fruits.size();
        if(n == 1 || n == 2)
            return n;

        //initialize 6 variables , each 3 of them to track one basket (fruit type, fruit no in it, streak till i-th tree)
        int fruit_type1 = fruits[0], fruit_type2 = fruits[1];
        int fruits_no_in_basket1 = 1, fruits_no_in_basket2 = 0;
        int streak_type1 = 1, streak_type2 = 0;

        bool prev_turn = 0; //tracking the previous turn (0=>fruit type 1 || 1=>fruit type 2)

        int i = 1;
        //what is the 2nd fruit type? get it
        for(; i < n; ++i){
            if(fruits[i] != fruit_type1){
                fruit_type2 = fruits[i];
                fruits_no_in_basket2 = streak_type2 = 1;
                ++i;
                prev_turn = 1;
                break;
            }

            fruits_no_in_basket1 = ++streak_type1;
        }

        // keep maximizing using  max_fruits_no_so_far
        int max_fruits_no_so_far = fruits_no_in_basket1 + fruits_no_in_basket2;


        for(; i < n; ++i){
            //if it is not one of either fruit types
            if(fruits[i] != fruit_type1 && fruits[i] != fruit_type2){
                //first get the max total no of fruits till this point
                max_fruits_no_so_far = max(max_fruits_no_so_far, fruits_no_in_basket1 + fruits_no_in_basket2);
                /*
                    then, keep the basket of the previous fruit type with u
                        but with the no of consecutive fruits till now only (streak)

                    and reset (empty) the other basket to contain this NEW TYPE!!
                    and put this new one in it
                */

                // so, prev fruit is of type 1 ?
                                    // => change no of fruits of type 1 in the basket to be the no of last consecutive fruits only (streak)
                                    // => change variables of type 2 to indicate that there is only one fruit inside (current one)

                if(fruits[i-1] == fruit_type1){
                    //type 2 indicates the current fruit type
                    fruit_type2 = fruits[i];
                    fruits_no_in_basket2 = streak_type2 = 1;

                    //type 1 is the same with the last streak
                    fruits_no_in_basket1 = streak_type1;

                    //mark prev_turn to indicate this current fruit type (for use in the next iteration)
                    prev_turn = 1; //type 2

                }
                //same with it of type 2
                else if (fruits[i-1] == fruit_type2){
                    //type 1
                    fruit_type1 = fruits[i];
                    fruits_no_in_basket1 = streak_type1 = 1;
                    //type 2
                    fruits_no_in_basket2 = streak_type2;

                    prev_turn = 0; //type 1
                }
                //if it is neither of type 1 nor type 2 =>
                //              change variables of type 1 to indicate that there is only one fruit inside (current one)
                //              reset variables of type 2 and its type will be known later (if any fruit then came of a type rather than type 1)
                else{
                    //type 1 (current fruit type)
                    fruit_type1 = fruits[i];
                    fruits_no_in_basket1 = 1;
                    streak_type1 = 1;

                    //type 2 (unknown type)
                    //          - intially mark it also as the current type
                    //            to force entering this "if section" if different type came later
                    //            so, type 2 is set correctly
                    fruit_type2 = fruits[i];
                    fruits_no_in_basket2 = 0;
                    streak_type2 = 0;

                    prev_turn = 0; //type 1
                }
            }
            //if this is already one of the 2 types we r collecting
            //get it in!! and don't forget to reset the streak of the other type
            //(because this current fruit type will destroy the other one type's streak)

            //type 1 ?
            else if(fruits[i] == fruit_type1)   {
                //come into the type 1 basket
                ++fruits_no_in_basket1;
                //streak detection depending on the previous fruit type :
                // still the same as type 1 ? contnuie this streak :)
                //else start from 1 again :(
                streak_type1 = (prev_turn == 0 ? streak_type1 + 1: 1);

                //destroy streak of type 2
                streak_type2 = 0;

                prev_turn = 0; // type 1 turn
            }
            else if(fruits[i] == fruit_type2)   {
                //type 2:
                ++fruits_no_in_basket2;
                streak_type2 = (prev_turn == 1 ? streak_type2 + 1 : 1);

                //type 1
                streak_type1 = 0;

                prev_turn  = 1; // type 2 turn
            }
        }

        //maximize for the last time
        max_fruits_no_so_far = max(max_fruits_no_so_far, fruits_no_in_basket1 + fruits_no_in_basket2);

        return max_fruits_no_so_far;

    }
};
