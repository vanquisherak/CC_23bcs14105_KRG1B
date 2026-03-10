class Solution {
    public int[] bellmanFord(int n, int[][] edges, int src) {
        int[] dist=new int[n];
        int inf=(int)1e8;
        Arrays.fill(dist,inf);
        dist[src]=0;
        for(int i=0;i<n-1;i++){
            for(int[] e:edges){
                int u=e[0];
                int v=e[1];
                int w=e[2];
                
                if(dist[u]!=inf && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        for(int[] e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            
            if(dist[u]!=inf && dist[u]+w<dist[v]){
                return new int[]{-1};
            }
        }
        return dist;
    }
}
