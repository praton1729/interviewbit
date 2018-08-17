/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int find_pivot(int* A, int low, int high){
    
    if(high<low){   return -1;}
    if(high==low){  return low;}
    
    int mid = (high+low)/2;
    
    if(*(A+mid)>*(A+mid+1)){
        return mid;
    }
    
    if(*(A+mid-1)>*(A+mid)){
        return mid-1;
    }
    
    if(*(A+mid)<=*(A+low)){
        return find_pivot(A,low,mid-1);
    }
    else{
        return find_pivot(A,mid+1,high);
    }
}

int binarySearch(int* arr, int low,int high, int key)
{
  if(high < low){
    return -1;
  }
  int mid = (low + high)/2; /*low + (high - low)/2;*/
  if(key == *(arr+mid)){
    return mid;
  }
  if(key > *(arr+mid)){
    return binarySearch(arr, (mid + 1), high, key);
  }
  else
  {
    return binarySearch(arr, low, (mid -1), key);
}    

}

int search(const int* A, int n1, int B) {
    
    int pivot = find_pivot(A, 0, n1-1);
    
    if(pivot==-1){
        return binarySearch(A, 0, n1-1, B);
    }
    
    if(*(A+pivot)==B){
        return pivot;
    }
    
    if(*(A)<=B){
        return binarySearch(A, 0, pivot-1,B);
    }
    else{
        return binarySearch(A, pivot+1, n1-1,B);
    }
}

