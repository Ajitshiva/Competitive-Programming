import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class demo {
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static boolean isValid(int i, int j, int r, int c) {
        return 0 <= i && i < r && 0 <= j && j < c;
    }

    static void dfs(int i, int j, int r, int c, char[][] grid)
    {
        Stack<int[]> stack = new Stack<>();
        grid[i][j] = '^';
        stack.push(new int[]{i, j});
        outer:
        while (!stack.isEmpty())
        {
            int count = 0;
            int[] top = stack.pop();
            i = top[0]; j = top[1];
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(isValid(x, y, r, c) && grid[x][y] == '.') {
                    grid[x][y] = '^';
                    stack.push(new int[]{x, y});
                    continue outer;
                }
            }
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(isValid(x, y, r, c) && grid[x][y] == '^') count++;
            }
            if(count < 2) grid[i][j] = 'x';
        }
    }

    static boolean verify(int r, int c, char[][] grid)
    {
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '^') {
                    int count = 0;
                    for(int k=0; k<4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(isValid(x, y, r, c) && grid[x][y] == '^') count++;
                    }
                    if(count < 2) return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int maxT = Integer.parseInt(br.readLine());
        for(int t = 1; t <= maxT; t++)
        {
            String[] input = br.readLine().split(" ");
            int r = Integer.parseInt(input[0]);
            int c = Integer.parseInt(input[1]);
            char[][] grid = new char[r][c];
            for(int i=0; i<r; i++)
                grid[i] = br.readLine().toCharArray();
            for(int i=0; i<r; i++)
                for (int j=0; j<c; j++)
                    if(grid[i][j] == '.') dfs(i, j, r, c, grid);
            if(verify(r, c, grid))
            {
                System.out.println("Case #" + t + ": Possible");
                for(int i=0; i<r; i++)
                {
                    for(int j=0; j<c; j++) {
                        if(grid[i][j] == 'x') System.out.print('.');
                        else System.out.print(grid[i][j]);
                    }
                    System.out.println();
                }
            }
            else {
                System.out.println("Case #" + t + ": Impossible");
            }
        }
    }
}