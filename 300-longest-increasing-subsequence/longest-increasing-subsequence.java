class Solution {
    public int lengthOfLIS(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        int size = nums.length;
        for(int i=0; i<size; i++){
            set.add(nums[i]);
        }

        int nums2[] = new int[set.size()];
        int i=0;
        for(int num:set){
            nums2[i++]=num;
        }

        Arrays.sort(nums2);

        return lcs(nums,nums2);
    }
    static int lcs(int arr1[] , int arr2[]){
        int n=arr1.length;
        int m=arr2.length;
        int dp[][] = new int[n+1][m+1];
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(arr1[i-1]==arr2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    int ans1 = dp[i-1][j];
                    int ans2 = dp[i][j-1];
                    dp[i][j] = Math.max(ans1,ans2);
                }
            }
        }
        
        return dp[n][m];
    }
}