/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void cam(int* a, int* b){//this function swaps the value in the positions of two(a and b) numbers
    int temp=*a;
    *a=*b;
    *b=temp;
 }
void backtrack(int* nums, int numSize, int start, int** per, int* count){
 //base case, if start reaches the end, store the current permutation
    if(start==numSize){
     //allocate memory for the new permutation
        per[*count]=(int*)malloc(numSize*sizeof(int));
        for(int i=0;i<numSize;i++){
            per[*count][i]=nums[i];//copies the current permutation
        }
        (*count)++;return;//returns the permutation count
    }
 //Loop through the remaining elements to generate permutations
    for(int i=start;i<numSize;i++){
     //calls the function to swap the elements in nums[start] with the one in nums[i] to fix a number in the start position
        cam(&nums[start], &nums[i]);
     //recursively calls backtrack with the next position fixed
        backtrack(nums, numSize, start+1, per, count);
     //swaps back to restore the original order
        cam(&nums[start], &nums[i]);//reverts the result from backtracking
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int fact=1;
    //calculates the permutations
    for(int i=2;i<=numsSize;i++){
        fact*=i;
    }
    //reserves memory for all the permutations
    int ** per=(int**)malloc(fact*sizeof(int*));
    *returnColumnSizes=(int*)malloc(fact*sizeof(int));

//inicilizates returnsize and gets permutations
    *returnSize=0;
    backtrack(nums, numsSize, 0, per, returnSize);

    //arranges each permutation
    for(int i=0; i<fact;i++){
        (*returnColumnSizes)[i]=numsSize;
    }
    return per;

}
