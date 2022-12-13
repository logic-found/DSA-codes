
        TreeNode* newnode=new TreeNode(0);
        newnode->left=root1->left;
        newnode->right=root1->right;
        
        if(mp[root2]==root1){
                bool left=false;
                if(root1->left==root2) left=true;
            
                root1->left=root2->left;
                root1->right=root2->right;
            
                if(left){
                    root2->left=root1;
                    root2->right=newnode->right;}
                else{
                    root1->right=root1;
                    root2->left=newnode->left;}
                root=root2;
        }
        else{
            root1->left=root2->left;
            root1->right=root2->right;
            root2->left=newnode->left;
            root2->right=newnode->right;

            cout<<root1->val<<root2->val<<endl;
            if(mp.find(root1)==mp.end()){
                if(mp[root2]->left==root2) mp[root2]->left=root1;
                else mp[root2]->right=root1;
                root=root2;
                print(root2);
            }
            else if(mp.find(root2)==mp.end()){
                if(mp[root1]->left==root1) mp[root1]->left=root2;
                else mp[root1]->right=root2;
                root=root1;

            }
            else{
                    TreeNode* par1=mp[root1];
                    TreeNode* par2=mp[root2];
                    bool left=false;
                    if(par2->left==root2) left=true;

                    if(par1->left==root1) par1->left=root2;
                    else par1->right=root2;

                    if(left) par2->left=root1;
                    else par2->right=root1;
            } 
        }
        