// Author : Omar Ashour

<?php 

class Solution {

    /**
     * @param Integer[] $tasks
     * @return Integer
     */
    function minimumRounds($tasks) {
        // Initialize a map to calculate the frequency of the numbers
        $map = [];
        $ans = 0;
        // Calculate the frequency of numbers
        foreach($tasks as $task)
            $map[$task]++;

        foreach($map as $key => $value){
            // If the frequency less than 2 or 3, then task can't be done
            if($value == 1)
                return -1;
            // Calculate how many 3's can be taken from the value
            $ans += (int)($value / 3);
            // If no other 3 can be taken, increment by one (meaning that 2 is taken)
            $ans += ($value % 3 != 0);
        }
        return $ans;
    }
}
