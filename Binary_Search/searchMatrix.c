/**
 * @input A : 2D integer array ' * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * @input B : Integer
 * 
 * @Output Integer
 */
int searchMatrix(int** A, int n11, int n12, int B) {
    
    int i = 0;
    int j = n12-1;
    
    while(i<n11 && j>=0){
        
        if(*(*(A+i)+j)==B){
            return 1;
        }
        if(*(*(A+i)+j)>B){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}

