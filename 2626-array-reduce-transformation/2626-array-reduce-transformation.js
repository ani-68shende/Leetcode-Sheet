/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var temp = init;
    for(var i = 0 ; i < nums.length ; i++){
        temp = fn(temp, nums[i]);
    }
    return temp;
};