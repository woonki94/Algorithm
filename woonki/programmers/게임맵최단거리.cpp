import java.util.*;

public class Pos{
    int x;
    int y;
    int distance;
    
    public Pos(int x, int y, int distance){
        this.x = x;
        this.y = y;
        this.distance = distance;
    }
}

class Solution {
    
    
    public int solution(int[][] maps) {
        int answer = -1;
        int l = maps.length;
        int w = maps[0].length;
        
        int[] dir_x = {0,1,0,-1};
        int[] dir_y = {1,0,-1,0};
        
        Queue<Pos> q = new LinkedList<>();
        int[][] visited = new int[101][101];
        
        Pos init_p = new Pos(0,0,1);
        q.offer(init_p);
        
        while(!q.isEmpty()){
            Pos pos = q.poll();
            int now_x = pos.x;
            int now_y = pos.y;
            int now_d = pos.distance;
            
            if(now_x == l-1 && now_y ==w-1) answer = now_d;
            
            for(int i=0; i<4; i++){
                int next_x = now_x + dir_x[i];
                int next_y = now_y + dir_y[i];
                
                if(next_x<0 || next_x>= l || next_y<0 || next_y>=w ) continue;
                if(maps[next_x][next_y] == 0) continue;
                if(visited[next_x][next_y] == 1) continue;
                
                q.offer(new Pos(next_x, next_y, now_d+1));
                visited[next_x][next_y] = 1;
            }
        }
        
        
        
        return answer;
    }
}
