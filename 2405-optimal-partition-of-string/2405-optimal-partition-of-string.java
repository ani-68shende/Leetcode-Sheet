class Solution
{
public
    int partitionString(String str)
    {
        int ff = 0;
        int es = 0;
        Set<Character> map = new HashSet<>();
        while (ff < str.length())
        {
            if (map.contains(str.charAt(ff)))
            {
                es++;
                map.clear();
            }
            map.add(str.charAt(ff));
            ff++;
        }
        return es + 1;
    }
}