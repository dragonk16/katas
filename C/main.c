#include <stdio.h>
#include <malloc.h>
#include<stdbool.h>
#include <stdlib.h>
#include <string.h>


/*
char findMissingLetter(char array[], int arrayLength) {
    if (arrayLength == 2) {
        return (array[0] + array[1]) * 0.5;
    }

    int left = 0;
    int right = arrayLength - 1;
    int mid = (left + right) * 0.5;
    int leftLen = mid - left;
    if ((array[mid] - array[left]) != leftLen) {
        return findMissingLetter(array, leftLen + 1);
    }
    return findMissingLetter(array + leftLen, arrayLength - leftLen);
}
*/
/*
int dblLinear(int n) {
    int x;
    int* hist=calloc(10*n, sizeof(int));
    hist[1]=1;
    int cnt=0;
    for (int j = 0;; ++j) {
        if(hist[j]==1) {
            cnt++;
            if(cnt-1==n){
                return j;
            }
        }
        if (hist[j]==1){
            x=2*j+1;
            hist[x]=1;
            x=3*j+1;
            hist[x]=1;
        }
    }
    cnt=0;
    for (int j = 0;j<100; ++j) {
        if (hist[j] == 1) {
            x = 2 * j + 1;
            printf("%d,", x);
            hist[x] = 1;
            x = 3 * j + 1;
            printf("%d,", x);
            hist[x] = 1;
        }
    }
        printf("\n");
        for (int i = 0; i <100 ; ++i) {
            printf("%d,",i);
        }
}
*/
/*
int last_digit(const unsigned long int *arr, size_t arr_size) {
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
*/


/// last didit of a large number
/*
int last_two(const unsigned long int *arr, unsigned int arr_size) {
    if(arr_size==2 && arr[1]==0){
        return 1;
    }
    int pow;
    if (arr_size > 2) {
        pow = last_two(arr + 1, arr_size - 1);
    } else if(arr[1]==0){
        return 1;
    }
    else pow = arr[1] % 100;
    if (pow==-1)return 1;
    if(arr[0]==0) return -1;
    int dig = arr[0] % 10;
    if (dig == 1 || dig == 0) {
        return dig;
    }
    if(pow==1)return dig;
    int digToFour = dig % 4;

    switch (digToFour) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return (pow % 2 == 1) ? 3 : 1;
    }
}

int last_digit(const unsigned long int *arr, unsigned int arr_size) {
    if (arr_size==0)
        return 1;
    if (arr_size==1)
        return arr[0]%10;
    if(arr_size==2 && arr[1]==0){
        return 1;
    }
    int pow = 0;
    if (arr_size > 2) {
        pow = last_two(arr + 1, arr_size - 1);
    } else pow = arr[1]%100;
    if(pow==-1)
        return 1;
    int dig = arr[0] % 10;
    if (dig == 1 || dig == 0) {
        return dig;
    }

    int Scase = ((pow % 4 == 0) ? 4 : pow % 4);
    int ret = 1;
    for (int i = 0; i <Scase ; ++i) {
        ret *= dig;
    }
    return (ret % 10);
}

*/
/*
/// 4 aligned
void* NewMalloc(unsigned int bytes) {
    if (bytes == 0)
        return 0;
    void *ptr = malloc(bytes + 4);
    void *retVal = ptr;
    int x=(int) ptr;
    int jmp = x % 4;
    retVal = ptr + (4 - jmp);
    *(char *) (retVal - 1) = (4 - jmp);
    return retVal;
}

void NewFree(void* ptr){
    void* address=ptr-1;
    char jmp=*(char*)address;
    free(ptr-jmp);
}

*/
/*
bool validSolution(unsigned int board[9][9]){
    int sum=((1+9)*9)/2;
    ///rows

    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; i++) {
            sum=sum-board[j][i];
        }
        if(sum!=0){
            return false;
        }
        sum=((1+9)*9)/2;
    }
    ///cols
    sum=((1+9)*9)/2;
    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 9; i++) {
            sum=sum-(board[i][j]);
        }
        if(sum!=0){
            return false;
        }
        sum=((1+9)*9)/2;
    }
    ///squers
    sum=((1+9)*9)/2;
    for (int j = 1; j < 9; j+=3) {
        for (int i = 1; i < 9; i+=3) {
            ///checking squre
            for (int k = -1; k < 2; ++k) {
                for (int l = -1; l < 2; ++l) {
                    sum = sum - (board[i + k][j + l]);
                }
            }
            if (sum != 0) {
                return false;
            }
            sum = ((1 + 9) * 9) / 2;
        }
    }
    return true;
    }
*/
/*
///propogates the overflow through the output string
void propogate(char* str,int index){
    while(str[index]>9){
        str[index-1]= str[index-1]+str[index]/10;
        str[index]=str[index]%10;
        index--;
    }
}

///function works well, and does its work
///but it allocates the max number of bytes based on the lenght of the input,
///because of this we need to skip the leading zeros, and the reallocate output string
char *multiply(char *a, char *b) {
    int aLen = strlen(a), bLen = strlen(b);
    ///not including null
    unsigned int overflow = 0;
    int mul = 0;
    char *workStr = calloc(aLen + bLen + 1, sizeof(char));/// allocating space for the new string
    char* ptr=workStr;
    for (int i = aLen - 1; i >= 0; i--) {///going over string a
        for (int j = bLen - 1; j >= 0; j--) {/// going over string b
            mul = (a[i] - '0') * (b[j] - '0');
            workStr[i + j + 1] = workStr[i + j + 1] + (mul % 10) + overflow;
            if (workStr[i + j + 1] > 9)
                propogate(workStr, i + j + 1, aLen + bLen + 1);
            overflow = mul / 10;
        }
        workStr[i] = workStr[i] +overflow;
        overflow=0;
    }
    for (int k = 0; k < aLen + bLen; ++k) {
        workStr[k] += '0';
    }
    workStr[aLen + bLen] = 0;///adding null
    while (*workStr == '0') {///skipping zeros
        workStr++;
    }
    if (*workStr == 0) {///returning zero
        workStr--;
    }
    ///reallocating the string
    ///fixing the offset between the allocated address and start of the string(skipping zeros)
    char* Ret=malloc( sizeof(char)*(aLen + bLen + 1-(workStr-ptr)));
    memcpy(Ret,workStr,aLen + bLen + 1-(workStr-ptr));
    free(ptr);
    return Ret;
}

*/
/*
struct node {
    int data;
    struct node *next;
};
struct list {
    size_t sz;
    struct node *head;
};

struct list* createList();

// push data at the head of the list
void insertFirst(struct list* l, int data);

struct list* reverse(struct list* l);

void listFree(struct list* l);


///calculating the number of prime factors
int calcKval(int val) {
    int k = 0;
    while (val % 2 == 0) {
        val /= 2;
        k++;
    }
    for (int i = 3; i <= val;) {
        if (val % i == 0) {
            val /= i;
            k++;
        } else {
            i += 2;
        }
    }
    return k;
}
int consecKprimes(int k, struct list* l) {
    int cnt=0;
    int kValprev=0,kValcurr=0;
    for (struct node* it=l->head; it!=0 ; it=it->next) {//iterating over the list calculating kprime for every entry
        kValcurr = calcKval(it->data);
        if (kValcurr == k && kValcurr == kValprev )
            cnt++;
        kValprev = kValcurr;
    }
    return cnt;
}

int arr2k(int k, int* l,int len) {
    int cnt=0;
    int kValprev=0,kValcurr=0;
    for (int i=0;i<len;i++) {
        kValcurr = calcKval(l[i]);
        if (kValcurr == k && kValcurr == kValprev )
            cnt++;
        kValprev = kValcurr;
    }
    return cnt;
}
*/

struct node {
    int weigth;
    int index;
    int number;
};

void fillArr(struct node **arr ,char* str,int numOfElements){
    int weigth=0, number=0;
    int index=0;
    for (int i = 0; str[i] !=0 ; ++i) {
        if (str[i]==' '){
            arr[index]=malloc(sizeof(struct node));
            arr[index]->weigth=weigth;
            arr[index]->index=index;
            arr[index]->number=number;
            index++;
            number=0;
            weigth=0;
            continue;
        }
        number=(number*10)+(str[i]-'0');
        weigth=weigth+(str[i]-'0');
    }
    arr[index]=malloc(sizeof(struct node));
    arr[index]->weigth=weigth;
    arr[index]->index=index;
    arr[index]->number=number;
}

int getNumOfElements(char* str,int *largest){
    int cnt=1;
    int len=0;
    for (int i = 0; str[i] !=0 ; ++i) {
        if(str[i]==' ') {
            cnt++;
            if (len>*largest){
                *largest=len;
            }
            len = 0;
        }
        else{
            len++;
        }
    }
    if (len>*largest){
        *largest=len;
    }
    return cnt;
}

void bubbleSort(struct node** arr,int numOfElements){
    int maxWeight=0;
    struct node* temp;
    for (int i = 0; i < numOfElements; ++i) {
        for (int j = 0; j < numOfElements-i-1; ++j) {
            if (arr[j]->weigth>arr[j+1]->weigth){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            }
        }
    }
}

char* closest(char* strng) {
    if (strlen(strng) == 0) {
        char *output=malloc(sizeof("{{0,0,0},{0,0,0}}")+1);
        sprintf(output,"{{0,0,0},{0,0,0}}");
        return output;
    }
    int largest=0;
    int numOfElements = getNumOfElements(strng,&largest);
    struct node **arr = malloc(sizeof(struct node*) * numOfElements);
    fillArr(arr,strng, numOfElements);
    bubbleSort(arr,numOfElements);
    int diff=arr[1]->weigth-arr[0]->weigth,
    minIndex=0;
    for (int i = 1; i <numOfElements-1; ++i) {
        if(arr[i+1]->weigth-arr[i]->weigth<diff){
            diff=arr[i+1]->weigth-arr[i]->weigth;
            minIndex=i;
        }
    }
    void *output=malloc(sizeof(char)*largest*7);
    sprintf(output,"{{%d, %d, %d}, {%d, %d, %d}}",arr[minIndex]->weigth,arr[minIndex]->index,arr[minIndex]->number,
            arr[minIndex+1]->weigth,arr[minIndex+1]->index,arr[minIndex+1]->number);
    //TODO free arr
    return output;
}

int main() {
    char* s="456899 50 11992 176 272293 163 389128 96 290193 85 52";
    char* expr="{{13, 9, 85}, {14, 3, 176}}";
    char *sact = closest(s);
        if(strcmp(sact, expr) != 0)
            printf("Error. Expected \n %s \n but got \n %s \n", expr, sact);
        free(sact); sact = NULL;
}
