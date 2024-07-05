int search(int* nums, int numsSize, int target) {
    int j = numsSize-1, retorno = -1;
    for(int i = 0; i < numsSize; i++){
        if( nums[i] == target ){
            retorno = i;
            break;
        }else if ( nums[j] == target){
            retorno = j;
            break;
        }
        j--;
    }
    return retorno;
}
