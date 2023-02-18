//Author : Ubey Saab
var isAlienSorted = function(words, order) {
    let flage;// flage take true or false 
    // loop that iterate the elements of words 
    for(let i=0 ;i<words.length-1;i++)//big loop 

   {
    // variable take the longest value from current elements of words  which are words [i] and words[i+1]
       let longestString=words[i].length>words[i+1].length?words[i]:words[i+1]
    //    loop that iterats and reach the  letters in the words elements

        for ( let j=0;j<longestString.length;j++)//we will call this the small loop 
        {
          
            //if index of letter of words[i][j] in order   smaller than   words[i+1][j] make the flage true than break this small loop 
            if(order.indexOf(words[i][j]) < order.indexOf(words[i+1][j])){
                flage=true
                break;
            }
            // if words index in order is the same make flage true than try the next element 
            else if(order.indexOf(words[i][j]) == order.indexOf(words[i+1][j]))
            {
                flage=true
                continue;//trying the next element

            }
            // if our first word shorter than second one that will give us an undifined because we 'll use length out of the range of the first word  example [app,apple ]
            else if (words[i].length<words[i+1].length&& words[i][j]==undefined)

            {
                flage=true
                break;//break the small loop  we use break 

            }
            //anything else return false 
        else{
            flage=false
            return false
        }

            

        }
        
//be sure that return is outside the big loop 
    }
    return flage

    
};
console.log(isAlienSorted(["word","world","row"],"worldabcefghijkmnpqstuvxyz"))
console.log(isAlienSorted(["hello","leetcode"],"hlabcdefgijkmnopqrstuvwxyz"))
console.log(isAlienSorted(["apple","app"],"abcdefghijklmnopqrstuvwxyz"))
console.log(isAlienSorted(["fxasxpc","dfbdrifhp","nwzgs","cmwqriv","ebulyfyve","miracx","sxckdwzv","dtijzluhts","wwbmnge","qmjwymmyox"],"zkgwaverfimqxbnctdplsjyohu"
))
