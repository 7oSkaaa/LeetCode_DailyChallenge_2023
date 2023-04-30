// Author: Ahmed Gamal

// for this problem, we can represent the relations between the strings as a graph, where each node is a string (refrenced by its index in the array) and each edge is a relation between two strings (if they are similar or not)
// so we can use the disjoint set union (DSU) data structure to solve this problem, where each node will be represented by its index in the array and each node will have a parent node (initially each node is its own parent)
// and we will loop over the array of strings and for each string we will loop over the rest of the strings and check if they are similar or not, if they are similar and they are not in the same group (they have different parents) then we will join them in the same group (make the parent of the first string the parent of the second string)
// and the answer will be the number of groups in the DSU data structure

/**
 * @param {string[]} strs
 * @return {number}
 */

// DSU data structure
class DSU {
    constructor(n) {
        this.p = Array(n).fill(0);
        this.rank = Array(n).fill(0);

        for(let i = 0; i < n; i++) {
            this.p[i] = i;
        } 
    }

    get(x) {
        this.p[x] = x == this.p[x] ? x : this.get(this.p[x]);
        return this.p[x];
    }

    join(u, v) {
        u = this.get(u), v = this.get(v);

        if(u == v) {
            return;
        }

        if(this.rank[u] === this.rank[v]) {
            this.rank[u]++;
        }

        if(this.rank[u] > this.rank[v]) {
            this.p[v] = u;
        } else {
            this.p[u] = v;
        }
    } 
}

var numSimilarGroups = function(strs) {
    let n = strs.length;
    let d = new DSU(n);
    
    // initially each string is in its own group
    let ans = n;
    for(let i = 0; i < n; i++) {
        // m: length of the current string
        let m = strs[i].length;
        for(let j = i + 1; j < n; j++) {
            // cnt: number of different characters between the two strings
            let cnt = 0;
            for(let k = 0; k < m; k++) {
                // if the two strings are similar, then they will have at most 2 different characters
                cnt += strs[i][k] !== strs[j][k] ? 1 : 0;
            }

            // if the two strings are similar and they are not in the same group, then join them in the same group
            if((cnt === 0 || cnt === 2) && d.get(i) !== d.get(j)) {
                // decrease the number of groups by 1
                ans--;
                d.join(i, j);
            }
        }
    }

    // return the number of groups
    return ans;
};