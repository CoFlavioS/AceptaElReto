import java.util.ArrayDeque;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
    }
    public static void main(String Args[]){
        FastReader fr = new FastReader();
        boolean end = false;
        int rac, obj, minValue, i, temp;
        ArrayDeque<Integer> list = new ArrayDeque<>();

        rac = fr.nextInt();
        obj = fr.nextInt();

        while(rac!=0 && obj!=0 && !end){
            if(rac==0 && obj==0)end = true;
            minValue = Integer.MAX_VALUE;
            temp = 0;
            i = 0;
            while(i < rac || temp > obj){
                if(temp >= obj) {
                    temp -= list.remove().intValue();
                }
                if(temp < obj && i < rac){
                    list.add(fr.nextInt());
                    temp += list.getLast().intValue();
                    i++;
                }
                if(temp >= obj) {
                    minValue = Math.min(minValue, temp);
                }
            }
            list.clear();
            System.out.println( minValue == Integer.MAX_VALUE ? "IMPOSIBLE" : minValue );
            rac = fr.nextInt();
            obj = fr.nextInt();
        }
    }
}