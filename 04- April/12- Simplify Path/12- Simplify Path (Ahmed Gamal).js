// Author: Ahmed Gamal

// for this problem we will use stack to solve it
// we will split the path by / and then we will check if the current path is . or empty we will continue
// if the current path is .. we will pop the last element from the stack
// if the current path is not . or .. we will push it to the stack after adding /
// after that we will check if the last element in the stack is / and the length of the stack is more than 1 we will pop it
// if the length of the stack is 0 we will push / to it

// in the end we will join the stack and return it

/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let ans = [];
    path.split('/').forEach(i => {
        if(i === '..')
            ans.pop();
        else if(i !== '.' && i !== '')
            ans.push(i);
    });
    
    return '/' + ans.join('/');
};