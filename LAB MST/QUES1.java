import java.util.*;
public class Energy {
    public static void main(String[] args){
//        int[][] arr={{1,2},{2,4},{4,8}};
        int[][] arr={{1,3},{2,4},{10,11},{10,12},{8,9}};
        int ans=0;
        int energy=0;
        Arrays.sort(arr,(a,b)->(a[0]-a[1])-(b[0]-b[1]));
        for(int[] e:arr){
            int actual=e[0];
            int min=e[1];
            if(energy<min){
                ans+=(min-energy);
                energy=min;
            }
            energy-=actual;
        }
        System.out.println(ans);
    }
}
