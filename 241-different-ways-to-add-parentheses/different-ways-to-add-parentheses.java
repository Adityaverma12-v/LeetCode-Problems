class Solution {
    public List<Integer> diffWaysToCompute(String expression) 
    {
        List<Integer> ans = new ArrayList<>();
        int length = expression.length();

        for(int i =0; i<length; i++)
        {
            if( expression.charAt(i) == '+' || expression.charAt(i) == '-' || expression.charAt(i) == '*')
            {
                String leftString = expression.substring(0,i);
                String rightString = expression.substring(i+1);
                List<Integer> leftList = diffWaysToCompute(leftString);
                List<Integer> rightList = diffWaysToCompute(rightString);

                for(Integer left : leftList)
                {
                    for(Integer right : rightList)
                    {
                        int current;
                        switch(expression.charAt(i))
                        {
                            case '+':
                                current = left + right;
                                break;
                            case '-':
                                current = left - right;
                                break;
                            case '*':
                                current = left * right;
                                break;
                            default : 
                                current = 0;
                        }
                        ans.add(current);
                    }
                }
            }
        }
        if(ans.size() == 0)
            ans.add(Integer.valueOf(expression));
    
        return ans;
    }
}