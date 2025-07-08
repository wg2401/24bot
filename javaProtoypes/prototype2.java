package javaProtoypes;

public class prototype2
{
    public static void main(String[] args)
    {
        double[] nums = {80,1,112,1};
        int[] used = {0,0,0,0};
        String[] operationStrings = new String[3];
        int curStep = 0;

        String[] ans = findWay(nums, used, operationStrings, curStep);

        System.out.println(ans[0]);
        System.out.println(ans[1]);
        System.out.println(ans[2]);
    }


    public static String[] findWay(double[] nums, int[] used, String[] operationStrings, int curStep)
    {
        if (curStep == 3)
        {
            double check = 0;
            for (int i = 0; i < nums.length; i++)
            {
                if (used[i] == 0)
                {
                    check = nums[i];
                    break;
                }
            }

            // check for approx val to account for floating pt precision error
            if (Math.abs(check - 24.0) < 1e-6)
            {
                return operationStrings;
            }
            else
            {
                return null;
            }
        }

        double tempI, tempJ;
        String[] potAns;

        for (int i = 0; i < nums.length; i++)
        {
            if (used[i] == 0)
            {
                //mark i as used
                used[i] = 1;
                tempI = nums[i];

                for (int j = 0; j < nums.length; j++)
                {
                    //check for used (covers i = j case)
                    if (used[j] == 0)
                    {
                        tempJ = nums[j];
                        
                        //prevent duplicate commutative ops
                        if (i<j)
                        {
                            //add nums[i] and nums[j] and recurse
                            nums[j] = tempI + tempJ;
                            operationStrings[curStep] = (i+1) + "q" + (j+1);
                            potAns = findWay(nums, used, operationStrings, curStep + 1);
                            if (potAns!=null)
                            {
                                return potAns;
                            }
                        

                            //multiply and recurse
                            nums[j] = tempI * tempJ;
                            operationStrings[curStep] = (i+1) + "e" + (j+1);
                            potAns = findWay(nums, used, operationStrings, curStep + 1);
                            if (potAns!=null)
                            {
                                return potAns;
                            }
                        }

                        //nums[i]/nums[j] and recurse
                        if (Math.abs(tempJ) > 1e-9)
                        {
                            nums[j] = tempI/tempJ;
                            operationStrings[curStep] = (i+1) + "r" + (j+1);
                            potAns = findWay(nums, used, operationStrings, curStep + 1);
                            if (potAns!=null)
                            {
                                return potAns;
                            }
                        }

                        //nums[i] - nums[j] and recurse
                        nums[j] = tempI - tempJ;
                        operationStrings[curStep] = (i+1) + "w" + (j+1);
                        potAns = findWay(nums, used, operationStrings, curStep + 1);
                        if (potAns!=null)
                        {
                            return potAns;
                        }

                        //backtrack:
                        nums[j] = tempJ;
                    }
                }

                used[i] = 0;
            }
        }
        

        return null;
    }
}
