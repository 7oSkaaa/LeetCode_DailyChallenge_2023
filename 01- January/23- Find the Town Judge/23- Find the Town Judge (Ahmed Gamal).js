// Author: Ahmed Gamal

/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */

// we want to find the judge
// the judge trusts no one and everyone trusts the judge (we can use this to find the judge)
// notice that the judge is the only person who trusts no one and everyone trusts him but everyone can trust more than one person
// we can use a array<bool> vis(n + 1) to mark the people who trust someone (we will use 1-based indexing) and a array<int> cnt(n + 1) to count the number of people who trust each person (we will use 1-based indexing)
// we will use a for(array<int, int> p : trust) loop to iterate over the trust array and update vis and cnt (destructuring assignment is used to get the values of the pair)

var findJudge = function(n, trust) {
    // the judge
    let who = 0;
    // vis[i] = true if person i trusts someone
    let vis = Array(n + 1).fill(false);
    // cnt[i] = the number of people who trust person i
    let cnt = Array(n + 1).fill(0);

    // update vis and cnt (destructuring assignment is used to get the values of the pair)
    trust.forEach(([u, v]) => {
        vis[u] = true;
        cnt[v]++;
    });

    // find the judge (the person who trusts no one and everyone trusts him (if we add 1 to cnt[i] and it becomes n, then person i is the judge)))
    cnt.forEach((x, idx) => {
        if(++x === n && !vis[idx]){
            who = idx;
        }
    });

    // return the judge or -1 if there is no judge (if there is no judge, who will be 0)
    return who || -1;
};