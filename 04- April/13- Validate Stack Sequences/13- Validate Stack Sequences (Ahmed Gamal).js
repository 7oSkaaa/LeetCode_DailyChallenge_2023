// Author: Ahmed Gamal

// for this problem we will use stack to validate the sequence
// since the array is pushed in order we will push the elements in the stack until we find the first element in the popped array
// and since the numbers are unique, this will not cause any problem
// if we don't find the element in the stack we will push the next elements in the pushed array until we find it or the pushed array is empty
// if we find the element in the stack we will pop it and continue
// if we don't find the element in the stack we will return false

/**
* @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */

var validateStackSequences = function(pushed, popped) {
    // stk: stack
    // i: index of the pushed array
    let stk = [], i = 0;

    // ok: boolean to check if the sequence is valid
    let ok = true;

    // for each element in the popped array
    popped.forEach(x => {
        // if the stack is empty or the last element in the stack is not the current element
        if(stk.length === 0 || stk[stk.length - 1] !== x) {
            // push the elements in the pushed array until we find the current element or the pushed array is empty
            while(i < pushed.length) {
                stk.push(pushed[i++]);

                // if we find the current element in the stack we will break
                if(stk[stk.length - 1] === x) {
                    break;
                }
            }
        }
        
        // if the stack is empty or the last element in the stack is not the current element
        if(stk.length === 0 || stk[stk.length - 1] !== x) {
            // the sequence is not valid
            ok = false;
        } else {
            // pop the last element from the stack and continue
            stk.pop();
        }
    });

    // return the boolean
    return ok;
};