/**
 * @param {Object} object
 * @param {Function} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
    if(obj == null)return false;
    if(obj.constructor === classFunction)
    {
        return true;
    }
    obj = Object.getPrototypeOf(obj);
    return checkIfInstanceOf(obj, classFunction);
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */