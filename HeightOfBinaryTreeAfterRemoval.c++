using pii = pair<int,int>;

class Solution {
public:
    // in out time pairs at particular depth
    vector<pii> g[100005];
    
    int in[100005];
    int out[100005];
    int timer = 0;
    
    // Max Depth Overall
    int mx;

    
    // Calculating in out times for each vertex
    // postorder assignment
    void dfs(TreeNode* root, int depth)
    {
        if(root == nullptr)return;
        
        in[root -> val] = timer++;

        dfs(root -> left,depth + 1);
        dfs(root -> right, depth + 1);

        out[root -> val] = timer++;

        g[depth].push_back({in[root -> val], out[root -> val]});
        mx = max(mx,depth);
    }

    // check for particular height
    int check(int mid, int src)
    {
        if(g[mid].size() == 0) return 0;

        // check if first vertex don't lie in subtree of src
        if(!(g[mid][0].first >= in[src] && g[mid][0].second <= out[src])) return 1;

        // check if last vertex don't lies in subtree of src
		// Checking first and last is sufficient becase other middle vartices are in range of timings
        if(!(g[mid].back().first >= in[src] && g[mid].back().second <= out[src])) return 1;


        return 0;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {

        for(int i=0;i;i++)
        {
            if(g[i].size() == 0)break;
            g[i].clear();
        }

        // resetting 
        timer = 0;
        mx = 0;
        dfs(root,0);
        
        
        vector<int> ans;

        for(int q:queries)
        {
            int lo = 0;
            int hi = mx;
            int h = 1;

            while(lo <= hi)
            {
                int mid = (lo + hi) / 2;

                if(check(mid,q))
                {
                    h = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }

            ans.push_back(h);
        }

        return ans;
    }
};