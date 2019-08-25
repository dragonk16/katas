#include <iostream>
#include <intrin.h>
#include <list>
#include <cmath>
#include <vector>
#include "Katas.hpp"


using namespace std;

/*
int last_digit(std::string str1, std::string str2) {
    if (str2.front()=='0'){
        return 1;
    }
    int dig = str1.back() - '0';
    if (dig == 1 || dig == 0) {
        return dig;
    }
    int pow = 0;
    if (str2.size() > 1) {
        pow = (str2[str2.size()-1] - '0') + (10 *( str2[str2.size() - 2] - '0'));
    } else pow = str2.back() - '0';
    int Scase = ((pow % 4==0) ? 4 : pow % 4 ) ;
    int ret = 1;
    while (Scase != 0) {
        ret *= dig;
        Scase--;
    }
    return ret > 10? ret%10 : ret;
}

int main() {
    printf("%d--%d",last_digit("4", "1"),4);
    printf("\n");
    printf("%d--%d",last_digit("4", "2"),6);
    printf("\n");
    printf("%d--%d",last_digit("9", "7"),9);
    printf("\n");
    printf("%d--%d",last_digit("10", "10000000000"),0);
    printf("\n");
    printf("%d--%d",last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"),6);
    printf("\n");
    printf("%d--%d",last_digit("3715290469715693021198967285016729344580685479654510946723",
                               "68819615221552997273737174557165657483427362207517952651"),7);

    return 0;
}

//Assert::That(last_digit("4", "1"), Equals(4));
//Assert::That(last_digit("4", "2"), Equals(6));
//Assert::That(last_digit("9", "7"), Equals(9));
//Assert::That(last_digit("10", "10000000000"), Equals(0));
//Assert::That(last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"), Equals(6));
//Assert::That(last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"), Equals(7));
*/
/*
class PrimeDecomp
{
public:
    static std::string factors(int lst);
};


std::string PrimeDecomp::factors(int lst) {
    string str;
    if (lst==1 || lst==0){
            str.push_back('(');
            str.append(to_string(lst));
            str.push_back(')');
        return str;
    }
    int num = lst;
    int occurences=0;
    for (int i = 2; i <= 2;) {
        if (num % i == 0) {
            num = num / i;
            occurences++;
        } else {
            if (occurences != 0) {
                str.push_back('(');
                str.append(to_string(i));
                if (occurences != 1) {
                    str.push_back('*');
                    str.push_back('*');
                    str.append(to_string(occurences));
                }
                str.push_back(')');
                occurences = 0;
            }
            i++;
        }
    }
    int limit=0.5*lst;
    for (int i = 3; i <=limit;) {
        if (num % i == 0) {
            num = num / i;
            occurences++;
        } else {
            if (occurences != 0) {
                str.push_back('(');
                str.append(to_string(i));
                if (occurences != 1) {
                    str.push_back('*');
                    str.push_back('*');
                    str.append(to_string(occurences));
                }
                str.push_back(')');
                occurences = 0;
            }
            i=i+2;
        }
    }

    if(str.length()==0) {
        str.push_back('(');
        str.append(to_string(num));
        str.push_back(')');
    }
    return str;
}
*/
/*
class BestTravel
{
public:
    static int chooseBestSum(int kilometers, int towns, std::vector<int>& ls) {
        int size = ls.size();
        int sum = -1;
        int testsum=0;
        if (towns > size) return sum;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                for (int k = j + 1; k < size; ++k) {
                    testsum=ls[i] + ls[j] + ls[k];
                    if (sum < testsum && testsum <= kilometers) {
                        sum = testsum;
                    }
                }
            }
        }
        return sum;
    }
};
*/
/*
static int chooseBestSum(int kilometers, int towns, std::vector<int>& ls) {
    int sum=0;
    if(towns==1){
        for (int i = 0; i < ; ++i) {
            
        }
        
    }
    ///stopping
    chooseBestSum(kilometers-ls[0],towns-1,&(ls[0])+1);
    


}
 */
int main() {

PathFinderPart x;
x.test2();
}