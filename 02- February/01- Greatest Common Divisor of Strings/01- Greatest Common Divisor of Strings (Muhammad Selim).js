// Author: Muhammad Selim

/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
const gcdOfStrings = function(str1, str2) {
    if (str1 + str2 !== str2 + str1) {
        // There is no string that divides both str1 and str2
        return "";
    }

    // Calculate the GCD of the lengths of str1 and str2
    const gcdLength = gcd(str1.length, str2.length);

    return str1.substring(0, gcdLength);
};

// Calculate the GCD of two numbers
const gcd = (a, b) => {
    return b === 0 ? a : gcd(b, a % b);
}

console.log(gcdOfStrings(str1 = "ABCABC", str2 = "ABC"));
console.log(gcdOfStrings(str1 = "ABABAB", str2 = "ABAB"));
console.log(gcdOfStrings(str1 = "LEET", str2 = "CODE"));