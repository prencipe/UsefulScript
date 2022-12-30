{
//TChain chain("Vars_2_LegendreP0ChB_LegendreP2ChB_/all/bkgd");

TChain chain("Vars_5_deltaz_disc_CosTMax_LegendreP0ChB_LegendreP2ChB_/all/sig");
chain.Add("5var_cc.root");
chain.Add("5var_uds.root");
//chain.Add("fisher_5var_bb.root");

chain.Merge("5_udsc_sig.root");

}
