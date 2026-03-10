import java.util.*;
public class MaxLength {
    public static void main(String[] args){
        String [] s={"abcw","baz","foo","bar","xtfn","abcdef"};
//        String [] s={"a","ab","abc","d","cd","bcd","abcd"};
        int n=s.length;
        int[] mask=new int[n];
        for(int i=0;i<n;i++){
            int m=0;
            for(int j=0;j<s[i].length();j++){
                int ch=s[i].charAt(j)-'a';
                m|=(1<<ch);
            }
            mask[i]=m;
        }
        long res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask[i]&mask[j])==0){
                    res=Math.max(res,(long)s[i].length()*s[j].length());
                }
            }
        }
        System.out.println(res);
    }
}
