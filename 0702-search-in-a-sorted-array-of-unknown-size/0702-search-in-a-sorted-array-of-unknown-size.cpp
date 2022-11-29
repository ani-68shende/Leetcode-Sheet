/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    //cp  ok
    int search(const ArrayReader& reader, int target) {
        int right=1, left=0;

        if(reader.get(0) == target)
            return 0;

        //search boundary
        while(reader.get(right) < target)
        {
            left = right;
            right *= 2;
        }

        //normal bs
        while(left<=right)
        {
            int mid = ( right + left )/2;

            if( reader.get(mid) == target)
                return mid;
            else if( target > reader.get(mid) )    
                left = mid + 1 ;
            else 
                right = mid - 1;
        }    


        return -1;
    }
};