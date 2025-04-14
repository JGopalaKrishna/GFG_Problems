//{ Driver Code Starts
// Initial Template for Java
import java.util.*;


// } Driver Code Ends

// User function Template for Java
class Solution {
    public String findOrder(String[] words) {
        // code here
        Map<Character, Integer> inDeg = new HashMap<>();
        Map<Character, Set<Character>> graph = new HashMap<>();
        for(String word : words){
            for(char c : word.toCharArray()){
                inDeg.putIfAbsent(c, 0);
                graph.putIfAbsent(c, new HashSet<>());
            }
        }
        
        int n = words.length;
        for(int i = 0; i < n - 1; ++i){
            String w1 = words[i];
            String w2 = words[i + 1];
            if(w1.length() > w2.length() && w1.startsWith(w2)){
                return "";
            }
            int len = Math.min(w1.length(), w2.length());
            for(int j = 0 ; j < len; ++j){
                char c1 = w1.charAt(j);
                char c2 = w2.charAt(j);
                if(c1 != c2){
                    if(!graph.get(c1).contains(c2)){
                        inDeg.put(c2, inDeg.get(c2) + 1);
                        graph.get(c1).add(c2);
                    }
                    break;
                }
            }
        }
        
        Queue<Character> q = new LinkedList<>();
        
        for(Map.Entry<Character, Integer> entry : inDeg.entrySet()){
            if(entry.getValue() == 0){
                q.add(entry.getKey());
            }
        }
        StringBuilder order = new StringBuilder();
        
        while(!q.isEmpty()){
            char curr = q.poll();
            order.append(curr);
            for(char nbr : graph.get(curr)){
                inDeg.put(nbr, inDeg.get(nbr) - 1);
                if(inDeg.get(nbr) == 0){
                    q.add(nbr);
                }
            }
        }
        
        if(order.length() != inDeg.size()){
            return "";
        }
        
        return order.toString();
        
    }
}

//{ Driver Code Starts.

public class GFG {
    private static boolean validate(String[] original, String order) {
        Map<Character, Integer> mp = new HashMap<>();
        for (String word : original) {
            for (char ch : word.toCharArray()) {
                mp.put(ch, 1);
            }
        }
        for (char ch : order.toCharArray()) {
            if (!mp.containsKey(ch)) {
                return false;
            }
            mp.remove(ch);
        }
        if (!mp.isEmpty()) {
            return false;
        }

        Map<Character, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            indexMap.put(order.charAt(i), i);
        }

        for (int i = 0; i < original.length - 1; i++) {
            String a = original[i];
            String b = original[i + 1];
            int k = 0, n = a.length(), m = b.length();

            while (k < n && k < m && a.charAt(k) == b.charAt(k)) {
                k++;
            }

            if (k < n && k < m &&
                indexMap.get(a.charAt(k)) > indexMap.get(b.charAt(k))) {
                return false;
            }
            if (k != n && k == m) {
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine()); // Number of test cases

        while (t-- > 0) {
            String[] words = sc.nextLine().split(" ");
            String[] original = Arrays.copyOf(words, words.length);

            Solution ob = new Solution();
            String order = ob.findOrder(words);

            if (order.isEmpty()) {
                System.out.println("\"\"");
            } else {
                System.out.println(validate(original, order) ? "true" : "false");
            }
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends