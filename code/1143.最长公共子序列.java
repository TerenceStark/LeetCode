/*
 * @lc app=leetcode.cn id=1143 lang=java
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
import java.util.*;

class Solution {
    public int longestCommonSubsequence (String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m+1][n+1];

        for (int i = 1; i <= m; i++) {
            char char1 = text1.charAt(i-1);
            for (int j = 1; j <= n; j++) {
                char char2 = text2.charAt(j-1);
                if(char1 == char2){
                    dp[i][j] =  dp[i-1][j-1]+1;
                }            
                else{
                    dp[i][j] =  Math.max(dp[i-1][j],dp[i][j-1]);
                }   
            }
        }
        if(dp[m][n]!=0){
            return dp[m][n];
        }
        return 0;    
    }
}
// @lc code=end

