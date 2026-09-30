class Solution {
public:
    struct Node{
        int prod;
        int cnt[5];
        Node(){
            prod=1;
            for(int i=0;i<5;i++)
                cnt[i]=0;
        }
    };
    int k;
    vector<Node> tree;
    Node merge(Node a,Node b){
        Node res;
        res.prod=(a.prod*b.prod)%k;
        for(int i=0;i<k;i++)
        res.cnt[i]+=a.cnt[i];
        for(int i=0;i<k;i++){
            int r=(a.prod*i)%k;
            res.cnt[r]+=b.cnt[i];
        }
        return res;
    }
    void build(vector<int>& nums,int node,int l,int r){
        if(l==r){
            int x=nums[l]%k;
            tree[node].prod=x;
            tree[node].cnt[x]=1;
            return;
        }
        int mid=(l+r)/2;
        build(nums,2*node,l,mid);
        build(nums,2*node+1,mid+1,r);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
    void update(int node,int l,int r,int idx,int val){
        if(l==r){
            val%=k;
            tree[node]=Node();
            tree[node].prod=val;
            tree[node].cnt[val]=1;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)
            update(2*node,l,mid,idx,val);
        else
            update(2*node+1,mid+1,r,idx,val);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
    Node query(int node,int l,int r,int ql,int qr){
        if(ql<=l && r<=qr)
            return tree[node];
        int mid=(l+r)/2;
        if(qr<=mid)
            return query(2*node,l,mid,ql,qr);
        if(ql>mid)
            return query(2*node+1,mid+1,r,ql,qr);
        Node left=query(2*node,l,mid,ql,qr);
        Node right=query(2*node+1,mid+1,r,ql,qr);
        return merge(left,right);
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k=k;
        int n=nums.size();
        tree.resize(4*n);
        build(nums,1,0,n-1);
        vector<int> ans;
        for( auto q:queries){
            int ind=q[0];
            int val=q[1];
            int st=q[2];
            int x=q[3];
            update(1,0,n-1,ind,val);
            Node temp=query(1,0,n-1,st,n-1);
            ans.push_back(temp.cnt[x]);
        }
        return ans;
    }
};