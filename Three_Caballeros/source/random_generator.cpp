mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch
().count());
uniform_int_distribution<long long> dist(1,6);
cout<<dist(gen)<<endl;
