import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        var map=new HashMap<String,Integer>();
        for(int i=0;i<n;i++){
            String s=br.readLine();
            map.put(s,map.getOrDefault(s,0)+1);
        }
        int max=0;
        String ans="";
        for(var e:map.entrySet()){
            String name=e.getKey();
            int val=e.getValue();
            if(val>max){
                max=val;
                ans=name;
            }
        }
        System.out.println(ans);
    }
}
