#ifndef _TROUGH_PHYSICAL_COMMON_DATA_H_
#define _TROUGH_PHYSICAL_COMMON_DATA_H_

#include <stdio.h>

#include "../input_cases/code_generator_utilities.h"

//const char * SSCDIR = std::getenv("SSCDIR");
//const char * SAMNTDIR = std::getenv("SAMNTDIR");

char dispatch_factors_path_tp[512];
char ud_ind_od_path_tp[512];
char wlim_series_path_tp[512];


int ntp1 = sprintf(dispatch_factors_path_tp, "%s/test/input_cases/moltensalt_data/dispatch_factors_ts.csv",
                   std::getenv("SSCDIR"));
int ntp2 = sprintf(ud_ind_od_path_tp, "%s/test/input_cases/moltensalt_data/ud_ind_od.csv", std::getenv("SSCDIR"));
int ntp3 = sprintf(wlim_series_path_tp, "%s/test/input_cases/moltensalt_data/wlim_series.csv", std::getenv("SSCDIR"));

/**
*  Default data for trough_physical run that can be further modified
*/
void trough_physical_default(ssc_data_t &data) {
    char solar_resource_path[512];
    int n1 = sprintf(solar_resource_path,
                     "%s/test/input_cases/tcstrough_data/tucson_az_32.116521_-110.933042_psmv3_60_tmy.csv",
                     std::getenv("SSCDIR"));

    ssc_data_set_string(data, "file_name", solar_resource_path);
    ssc_data_set_number(data, "nSCA", 8);
    ssc_data_set_number(data, "nHCEt", 4);
    ssc_data_set_number(data, "nColt", 4);
    ssc_data_set_number(data, "nHCEVar", 4);
    ssc_data_set_number(data, "nLoops", 181);
    ssc_data_set_number(data, "FieldConfig", 2);
    ssc_data_set_number(data, "include_fixed_power_block_runner", 1);
    ssc_data_set_number(data, "L_power_block_piping", 50);
    ssc_data_set_number(data, "eta_pump", 0.84999999999999998);
    ssc_data_set_number(data, "Fluid", 21);
    ssc_data_set_number(data, "accept_loc", 1);
    ssc_data_set_number(data, "HDR_rough", 4.57e-05);
    ssc_data_set_number(data, "theta_stow", 170);
    ssc_data_set_number(data, "theta_dep", 10);
    ssc_data_set_number(data, "Row_Distance", 15);
    ssc_data_set_number(data, "T_loop_in_des", 293);
    ssc_data_set_number(data, "T_loop_out", 391);
    ssc_data_set_number(data, "m_dot_htfmin", 1);
    ssc_data_set_number(data, "m_dot_htfmax", 12);
    ssc_number_t p_field_fl_props[1] = {0};
    ssc_data_set_matrix(data, "field_fl_props", p_field_fl_props, 1, 1);
    ssc_data_set_number(data, "T_fp", 150);
    ssc_data_set_number(data, "I_bn_des", 950);
    ssc_data_set_number(data, "Pipe_hl_coef", 0.45000000000000001);
    ssc_data_set_number(data, "SCA_drives_elec", 125);
    ssc_data_set_number(data, "tilt", 0);
    ssc_data_set_number(data, "azimuth", 0);
    ssc_data_set_number(data, "wind_stow_speed", 25);
    ssc_data_set_number(data, "accept_mode", 0);
    ssc_data_set_number(data, "accept_init", 0);
    ssc_data_set_number(data, "solar_mult", 2);
    ssc_data_set_number(data, "mc_bal_hot", 0.20000000000000001);
    ssc_data_set_number(data, "mc_bal_cold", 0.20000000000000001);
    ssc_data_set_number(data, "mc_bal_sca", 4.5);
    ssc_number_t p_W_aperture[4] = {6, 6, 6, 6};
    ssc_data_set_array(data, "W_aperture", p_W_aperture, 4);
    ssc_number_t p_A_aperture[4] = {656, 656, 656, 656};
    ssc_data_set_array(data, "A_aperture", p_A_aperture, 4);
    ssc_number_t p_TrackingError[4] = {0.98799999999999999, 0.98799999999999999, 0.98799999999999999,
                                       0.98799999999999999};
    ssc_data_set_array(data, "TrackingError", p_TrackingError, 4);
    ssc_number_t p_GeomEffects[4] = {0.95199999999999996, 0.95199999999999996, 0.95199999999999996,
                                     0.95199999999999996};
    ssc_data_set_array(data, "GeomEffects", p_GeomEffects, 4);
    ssc_number_t p_Rho_mirror_clean[4] = {0.93000000000000005, 0.93000000000000005, 0.93000000000000005,
                                          0.93000000000000005};
    ssc_data_set_array(data, "Rho_mirror_clean", p_Rho_mirror_clean, 4);
    ssc_number_t p_Dirt_mirror[4] = {0.96999999999999997, 0.96999999999999997, 0.96999999999999997,
                                     0.96999999999999997};
    ssc_data_set_array(data, "Dirt_mirror", p_Dirt_mirror, 4);
    ssc_number_t p_Error[4] = {1, 1, 1, 1};
    ssc_data_set_array(data, "Error", p_Error, 4);
    ssc_number_t p_Ave_Focal_Length[4] = {2.1499999999999999, 2.1499999999999999, 2.1499999999999999,
                                          2.1499999999999999};
    ssc_data_set_array(data, "Ave_Focal_Length", p_Ave_Focal_Length, 4);
    ssc_number_t p_L_SCA[4] = {115, 115, 115, 115};
    ssc_data_set_array(data, "L_SCA", p_L_SCA, 4);
    ssc_number_t p_L_aperture[4] = {14.375, 14.375, 14.375, 14.375};
    ssc_data_set_array(data, "L_aperture", p_L_aperture, 4);
    ssc_number_t p_ColperSCA[4] = {8, 8, 8, 8};
    ssc_data_set_array(data, "ColperSCA", p_ColperSCA, 4);
    ssc_number_t p_Distance_SCA[4] = {1, 1, 1, 1};
    ssc_data_set_array(data, "Distance_SCA", p_Distance_SCA, 4);
    ssc_number_t p_IAM_matrix[12] = {1, 0.0327, -0.1351, 1, 0.0327, -0.1351, 1, 0.0327, -0.1351, 1, 0.0327, -0.1351};
    ssc_data_set_matrix(data, "IAM_matrix", p_IAM_matrix, 4, 3);
    ssc_number_t p_HCE_FieldFrac[16] = {0.98499999999999999, 0.01, 0.0050000000000000001, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
                                        0, 0, 0};
    ssc_data_set_matrix(data, "HCE_FieldFrac", p_HCE_FieldFrac, 4, 4);
    ssc_number_t p_D_2[16] = {0.075999999999999998, 0.075999999999999998, 0.075999999999999998, 0.075999999999999998,
                              0.075999999999999998, 0.075999999999999998, 0.075999999999999998, 0.075999999999999998,
                              0.075999999999999998, 0.075999999999999998, 0.075999999999999998, 0.075999999999999998,
                              0.075999999999999998, 0.075999999999999998, 0.075999999999999998, 0.075999999999999998};
    ssc_data_set_matrix(data, "D_2", p_D_2, 4, 4);
    ssc_number_t p_D_3[16] = {0.080000000000000002, 0.080000000000000002, 0.080000000000000002, 0.080000000000000002,
                              0.080000000000000002, 0.080000000000000002, 0.080000000000000002, 0.080000000000000002,
                              0.080000000000000002, 0.080000000000000002, 0.080000000000000002, 0.080000000000000002,
                              0.080000000000000002, 0.080000000000000002, 0.080000000000000002, 0.080000000000000002};
    ssc_data_set_matrix(data, "D_3", p_D_3, 4, 4);
    ssc_number_t p_D_4[16] = {0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115, 0.115,
                              0.115, 0.115, 0.115};
    ssc_data_set_matrix(data, "D_4", p_D_4, 4, 4);
    ssc_number_t p_D_5[16] = {0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12, 0.12,
                              0.12};
    ssc_data_set_matrix(data, "D_5", p_D_5, 4, 4);
    ssc_number_t p_D_p[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_matrix(data, "D_p", p_D_p, 4, 4);
    ssc_number_t p_Flow_type[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "Flow_type", p_Flow_type, 4, 4);
    ssc_number_t p_Rough[16] = {4.5000000000000003e-05, 4.5000000000000003e-05, 4.5000000000000003e-05,
                                4.5000000000000003e-05, 4.5000000000000003e-05, 4.5000000000000003e-05,
                                4.5000000000000003e-05, 4.5000000000000003e-05, 4.5000000000000003e-05,
                                4.5000000000000003e-05, 4.5000000000000003e-05, 4.5000000000000003e-05,
                                4.5000000000000003e-05, 4.5000000000000003e-05, 4.5000000000000003e-05,
                                4.5000000000000003e-05};
    ssc_data_set_matrix(data, "Rough", p_Rough, 4, 4);
    ssc_number_t p_alpha_env[16] = {0.02, 0.02, 0, 0, 0.02, 0.02, 0, 0, 0.02, 0.02, 0, 0, 0.02, 0.02, 0, 0};
    ssc_data_set_matrix(data, "alpha_env", p_alpha_env, 4, 4);
    ssc_number_t p_epsilon_3_11[18] = {100, 0.064000000000000001, 150, 0.066500000000000004, 200, 0.070000000000000007,
                                       250, 0.074499999999999997, 300, 0.080000000000000002, 350, 0.086499999999999994,
                                       400, 0.094, 450, 0.10249999999999999, 500, 0.112};
    ssc_data_set_matrix(data, "epsilon_3_11", p_epsilon_3_11, 9, 2);
    ssc_number_t p_epsilon_3_12[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_12", p_epsilon_3_12, 1, 1);
    ssc_number_t p_epsilon_3_13[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_13", p_epsilon_3_13, 1, 1);
    ssc_number_t p_epsilon_3_14[1] = {0};
    ssc_data_set_matrix(data, "epsilon_3_14", p_epsilon_3_14, 1, 1);
    ssc_number_t p_epsilon_3_21[18] = {100, 0.064000000000000001, 150, 0.066500000000000004, 200, 0.070000000000000007,
                                       250, 0.074499999999999997, 300, 0.080000000000000002, 350, 0.086499999999999994,
                                       400, 0.094, 450, 0.10249999999999999, 500, 0.112};
    ssc_data_set_matrix(data, "epsilon_3_21", p_epsilon_3_21, 9, 2);
    ssc_number_t p_epsilon_3_22[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_22", p_epsilon_3_22, 1, 1);
    ssc_number_t p_epsilon_3_23[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_23", p_epsilon_3_23, 1, 1);
    ssc_number_t p_epsilon_3_24[1] = {0};
    ssc_data_set_matrix(data, "epsilon_3_24", p_epsilon_3_24, 1, 1);
    ssc_number_t p_epsilon_3_31[18] = {100, 0.064000000000000001, 150, 0.066500000000000004, 200, 0.070000000000000007,
                                       250, 0.074499999999999997, 300, 0.080000000000000002, 350, 0.086499999999999994,
                                       400, 0.094, 450, 0.10249999999999999, 500, 0.112};
    ssc_data_set_matrix(data, "epsilon_3_31", p_epsilon_3_31, 9, 2);
    ssc_number_t p_epsilon_3_32[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_32", p_epsilon_3_32, 1, 1);
    ssc_number_t p_epsilon_3_33[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_33", p_epsilon_3_33, 1, 1);
    ssc_number_t p_epsilon_3_34[1] = {0};
    ssc_data_set_matrix(data, "epsilon_3_34", p_epsilon_3_34, 1, 1);
    ssc_number_t p_epsilon_3_41[18] = {100, 0.064000000000000001, 150, 0.066500000000000004, 200, 0.070000000000000007,
                                       250, 0.074499999999999997, 300, 0.080000000000000002, 350, 0.086499999999999994,
                                       400, 0.094, 450, 0.10249999999999999, 500, 0.112};
    ssc_data_set_matrix(data, "epsilon_3_41", p_epsilon_3_41, 9, 2);
    ssc_number_t p_epsilon_3_42[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_42", p_epsilon_3_42, 1, 1);
    ssc_number_t p_epsilon_3_43[1] = {0.65000000000000002};
    ssc_data_set_matrix(data, "epsilon_3_43", p_epsilon_3_43, 1, 1);
    ssc_number_t p_epsilon_3_44[1] = {0};
    ssc_data_set_matrix(data, "epsilon_3_44", p_epsilon_3_44, 1, 1);
    ssc_number_t p_alpha_abs[16] = {0.96299999999999997, 0.96299999999999997, 0.80000000000000004, 0,
                                    0.96299999999999997, 0.96299999999999997, 0.80000000000000004, 0,
                                    0.96299999999999997, 0.96299999999999997, 0.80000000000000004, 0,
                                    0.96299999999999997, 0.96299999999999997, 0.80000000000000004, 0};
    ssc_data_set_matrix(data, "alpha_abs", p_alpha_abs, 4, 4);
    ssc_number_t p_Tau_envelope[16] = {0.96399999999999997, 0.96399999999999997, 1, 0, 0.96399999999999997,
                                       0.96399999999999997, 1, 0, 0.96399999999999997, 0.96399999999999997, 1, 0,
                                       0.96399999999999997, 0.96399999999999997, 1, 0};
    ssc_data_set_matrix(data, "Tau_envelope", p_Tau_envelope, 4, 4);
    ssc_number_t p_EPSILON_4[16] = {0.85999999999999999, 0.85999999999999999, 1, 0, 0.85999999999999999,
                                    0.85999999999999999, 1, 0, 0.85999999999999999, 0.85999999999999999, 1, 0,
                                    0.85999999999999999, 0.85999999999999999, 1, 0};
    ssc_data_set_matrix(data, "EPSILON_4", p_EPSILON_4, 4, 4);
    ssc_number_t p_EPSILON_5[16] = {0.85999999999999999, 0.85999999999999999, 1, 0, 0.85999999999999999,
                                    0.85999999999999999, 1, 0, 0.85999999999999999, 0.85999999999999999, 1, 0,
                                    0.85999999999999999, 0.85999999999999999, 1, 0};
    ssc_data_set_matrix(data, "EPSILON_5", p_EPSILON_5, 4, 4);
    ssc_number_t p_GlazingIntactIn[16] = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
    ssc_data_set_matrix(data, "GlazingIntactIn", p_GlazingIntactIn, 4, 4);
    ssc_number_t p_P_a[16] = {0.0001, 750, 750, 0, 0.0001, 750, 750, 0, 0.0001, 750, 750, 0, 0.0001, 750, 750, 0};
    ssc_data_set_matrix(data, "P_a", p_P_a, 4, 4);
    ssc_number_t p_AnnulusGas[16] = {27, 1, 1, 27, 27, 1, 1, 27, 27, 1, 1, 27, 27, 1, 1, 27};
    ssc_data_set_matrix(data, "AnnulusGas", p_AnnulusGas, 4, 4);
    ssc_number_t p_AbsorberMaterial[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "AbsorberMaterial", p_AbsorberMaterial, 4, 4);
    ssc_number_t p_Shadowing[16] = {0.93500000000000005, 0.93500000000000005, 0.93500000000000005, 0.96299999999999997,
                                    0.93500000000000005, 0.93500000000000005, 0.93500000000000005, 0.96299999999999997,
                                    0.93500000000000005, 0.93500000000000005, 0.93500000000000005, 0.96299999999999997,
                                    0.93500000000000005, 0.93500000000000005, 0.93500000000000005, 0.96299999999999997};
    ssc_data_set_matrix(data, "Shadowing", p_Shadowing, 4, 4);
    ssc_number_t p_Dirt_HCE[16] = {0.97999999999999998, 0.97999999999999998, 1, 0.97999999999999998,
                                   0.97999999999999998, 0.97999999999999998, 1, 0.97999999999999998,
                                   0.97999999999999998, 0.97999999999999998, 1, 0.97999999999999998,
                                   0.97999999999999998, 0.97999999999999998, 1, 0.97999999999999998};
    ssc_data_set_matrix(data, "Dirt_HCE", p_Dirt_HCE, 4, 4);
    ssc_number_t p_Design_loss[16] = {190, 1270, 1500, 0, 190, 1270, 1500, 0, 190, 1270, 1500, 0, 190, 1270, 1500, 0};
    ssc_data_set_matrix(data, "Design_loss", p_Design_loss, 4, 4);
    ssc_number_t p_SCAInfoArray[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "SCAInfoArray", p_SCAInfoArray, 8, 2);
    ssc_number_t p_SCADefocusArray[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    ssc_data_set_array(data, "SCADefocusArray", p_SCADefocusArray, 8);
    ssc_data_set_number(data, "rec_su_delay", 0.20000000000000001);
    ssc_data_set_number(data, "rec_qf_delay", 0.25);
    ssc_data_set_number(data, "p_start", 0.021000000000000001);
    ssc_data_set_number(data, "pc_config", 0);
    ssc_data_set_number(data, "P_ref", 111);
    ssc_data_set_number(data, "eta_ref", 0.35599999999999998);
    ssc_data_set_number(data, "cycle_max_frac", 1.05);
    ssc_data_set_number(data, "cycle_cutoff_frac", 0.20000000000000001);
    ssc_data_set_number(data, "q_sby_frac", 0.20000000000000001);
    ssc_data_set_number(data, "startup_time", 0.5);
    ssc_data_set_number(data, "startup_frac", 0.20000000000000001);
    ssc_data_set_number(data, "pb_pump_coef", 0.55000000000000004);
    ssc_data_set_number(data, "dT_cw_ref", 10);
    ssc_data_set_number(data, "T_amb_des", 42);
    ssc_data_set_number(data, "P_boil", 100);
    ssc_data_set_number(data, "CT", 2);
    ssc_data_set_number(data, "tech_type", 1);
    ssc_data_set_number(data, "T_approach", 5);
    ssc_data_set_number(data, "T_ITD_des", 16);
    ssc_data_set_number(data, "P_cond_ratio", 1.0027999999999999);
    ssc_data_set_number(data, "pb_bd_frac", 0.02);
    ssc_data_set_number(data, "P_cond_min", 1.25);
    ssc_data_set_number(data, "n_pl_inc", 8);
    ssc_number_t p_F_wc[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_array(data, "F_wc", p_F_wc, 9);
    ssc_data_set_number(data, "ud_T_amb_des", 43);
    ssc_data_set_number(data, "ud_f_W_dot_cool_des", 0);
    ssc_data_set_number(data, "ud_m_dot_water_cool_des", 0);
    ssc_data_set_number(data, "ud_T_htf_low", 300);
    ssc_data_set_number(data, "ud_T_htf_high", 410);
    ssc_data_set_number(data, "ud_T_amb_low", 0);
    ssc_data_set_number(data, "ud_T_amb_high", 55);
    ssc_data_set_number(data, "ud_m_dot_htf_low", 0.29999999999999999);
    ssc_data_set_number(data, "ud_m_dot_htf_high", 1.2);
    set_matrix(data, "ud_ind_od", ud_ind_od_path_tp, 180, 7);
    ssc_data_set_number(data, "store_fluid", 18);
    ssc_number_t p_store_fl_props[1] = {1};
    ssc_data_set_matrix(data, "store_fl_props", p_store_fl_props, 1, 1);
    ssc_data_set_number(data, "is_hx", 1);
    ssc_data_set_number(data, "tshours", 6);
    ssc_data_set_number(data, "h_tank", 12);
    ssc_data_set_number(data, "u_tank", 0.40000000000000002);
    ssc_data_set_number(data, "tank_pairs", 1);
    ssc_data_set_number(data, "hot_tank_Thtr", 365);
    ssc_data_set_number(data, "hot_tank_max_heat", 25);
    ssc_data_set_number(data, "cold_tank_Thtr", 250);
    ssc_data_set_number(data, "cold_tank_max_heat", 25);
    ssc_data_set_number(data, "dt_hot", 5);
    ssc_data_set_number(data, "h_tank_min", 1);
    ssc_data_set_number(data, "init_hot_htf_percent", 30);
    ssc_number_t p_weekday_schedule[288] = {6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6,
                                            6, 6, 6, 6, 6, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6,
                                            6, 6, 6, 6, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6,
                                            6, 6, 6, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6,
                                            6, 6, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 3, 3, 3, 3, 3,
                                            3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 6, 6, 6, 6, 6, 6, 5, 5, 4,
                                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4,
                                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 5, 5, 4, 4, 4,
                                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5};
    ssc_data_set_matrix(data, "weekday_schedule", p_weekday_schedule, 12, 24);
    ssc_number_t p_weekend_schedule[288] = {6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6,
                                            6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6,
                                            6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6,
                                            6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
                                            6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3,
                                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                                            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 6, 6, 6, 6, 6, 6, 5, 5, 5,
                                            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5,
                                            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5,
                                            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    ssc_data_set_matrix(data, "weekend_schedule", p_weekend_schedule, 12, 24);
    ssc_data_set_number(data, "is_dispatch", 0);
    ssc_data_set_number(data, "disp_frequency", 24);
    ssc_data_set_number(data, "disp_horizon", 48);
    ssc_data_set_number(data, "disp_max_iter", 35000);
    ssc_data_set_number(data, "disp_timeout", 5);
    ssc_data_set_number(data, "disp_mip_gap", 0.001);
    ssc_data_set_number(data, "disp_time_weighting", 0.98999999999999999);
    ssc_data_set_number(data, "disp_rsu_cost", 950);
    ssc_data_set_number(data, "disp_csu_cost", 10000);
    ssc_data_set_number(data, "disp_pen_delta_w", 0.10000000000000001);
    ssc_data_set_number(data, "is_wlim_series", 0);
    set_array(data, "wlim_series", wlim_series_path_tp, 8760);
    ssc_number_t p_f_turb_tou_periods[9] = {1.05, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_array(data, "f_turb_tou_periods", p_f_turb_tou_periods, 9);
    ssc_data_set_number(data, "is_dispatch_series", 0);
    ssc_number_t p_dispatch_series[1] = {0};
    ssc_data_set_array(data, "dispatch_series", p_dispatch_series, 1);
    ssc_data_set_number(data, "pb_fixed_par", 0.0054999999999999997);
    ssc_number_t p_bop_array[5] = {0, 1, 0, 0.48299999999999998, 0};
    ssc_data_set_array(data, "bop_array", p_bop_array, 5);
    ssc_number_t p_aux_array[5] = {0.023, 1, 0.48299999999999998, 0.57099999999999995, 0};
    ssc_data_set_array(data, "aux_array", p_aux_array, 5);
    ssc_data_set_number(data, "gross_net_conversion_factor", 0.90000000000000002);
    ssc_data_set_number(data, "water_usage_per_wash", 0.69999999999999996);
    ssc_data_set_number(data, "washing_frequency", 63);
    ssc_data_set_number(data, "calc_design_pipe_vals", 1);
    ssc_data_set_number(data, "V_hdr_cold_max", 3);
    ssc_data_set_number(data, "V_hdr_cold_min", 2);
    ssc_data_set_number(data, "V_hdr_hot_max", 3);
    ssc_data_set_number(data, "V_hdr_hot_min", 2);
    ssc_data_set_number(data, "N_max_hdr_diams", 10);
    ssc_data_set_number(data, "L_rnr_pb", 25);
    ssc_data_set_number(data, "L_rnr_per_xpan", 70);
    ssc_data_set_number(data, "L_xpan_hdr", 20);
    ssc_data_set_number(data, "L_xpan_rnr", 20);
    ssc_data_set_number(data, "Min_rnr_xpans", 1);
    ssc_data_set_number(data, "northsouth_field_sep", 20);
    ssc_data_set_number(data, "N_hdr_per_xpan", 2);
    ssc_data_set_number(data, "offset_xpan_hdr", 1);
    ssc_number_t p_K_cpnt[121] = {0.90000000000000002, 0, 0.19, 0, 0.90000000000000002, -1, -1, -1, -1, -1, -1, 0,
                                  0.59999999999999998, 0.050000000000000003, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.41999999999999998, 0, 0.14999999999999999,
                                  0.050000000000000003, 0, 0.41999999999999998, 0, 0.59999999999999998, 0,
                                  0.59999999999999998, 0, 0.14999999999999999, 0.59999999999999998, 0,
                                  0.90000000000000002, 0, 0.19, 0, 0.90000000000000002, -1, -1, -1, -1, -1, -1};
    ssc_data_set_matrix(data, "K_cpnt", p_K_cpnt, 11, 11);
    ssc_number_t p_D_cpnt[121] = {0.085000000000000006, 0.063500000000000001, 0.085000000000000006,
                                  0.063500000000000001, 0.085000000000000006, -1, -1, -1, -1, -1, -1,
                                  0.085000000000000006, 0.085000000000000006, 0.085000000000000006,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.085000000000000006, 0.085000000000000006,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.085000000000000006, 0.085000000000000006, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.085000000000000006,
                                  0.085000000000000006, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.085000000000000006, 0.085000000000000006,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.085000000000000006, 0.085000000000000006, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.085000000000000006,
                                  0.085000000000000006, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.085000000000000006, 0.085000000000000006,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.085000000000000006, 0.085000000000000006, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.063500000000000001, 0.063500000000000001, 0.063500000000000001,
                                  0.085000000000000006, 0.085000000000000006, 0.085000000000000006,
                                  0.085000000000000006, 0.063500000000000001, 0.085000000000000006,
                                  0.063500000000000001, 0.085000000000000006, -1, -1, -1, -1, -1, -1};
    ssc_data_set_matrix(data, "D_cpnt", p_D_cpnt, 11, 11);
    ssc_number_t p_L_cpnt[121] = {0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
                                  0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0,
                                  1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
                                  0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                                  0, -1, -1, -1, -1, -1, -1};
    ssc_data_set_matrix(data, "L_cpnt", p_L_cpnt, 11, 11);
    ssc_number_t p_Type_cpnt[121] = {0, 1, 0, 1, 0, -1, -1, -1, -1, -1, -1, 1, 0, 0, 2, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2,
                                     0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 2,
                                     0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0,
                                     1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 1, 0, 2, 0, 0, 1,
                                     0, 1, 0, 1, 0, -1, -1, -1, -1, -1, -1};
    ssc_data_set_matrix(data, "Type_cpnt", p_Type_cpnt, 11, 11);
    ssc_data_set_number(data, "custom_sf_pipe_sizes", 0);
    ssc_number_t p_sf_rnr_diams[1] = {-1};
    ssc_data_set_matrix(data, "sf_rnr_diams", p_sf_rnr_diams, 1, 1);
    ssc_number_t p_sf_rnr_wallthicks[1] = {-1};
    ssc_data_set_matrix(data, "sf_rnr_wallthicks", p_sf_rnr_wallthicks, 1, 1);
    ssc_number_t p_sf_rnr_lengths[1] = {-1};
    ssc_data_set_matrix(data, "sf_rnr_lengths", p_sf_rnr_lengths, 1, 1);
    ssc_number_t p_sf_hdr_diams[1] = {-1};
    ssc_data_set_matrix(data, "sf_hdr_diams", p_sf_hdr_diams, 1, 1);
    ssc_number_t p_sf_hdr_wallthicks[1] = {-1};
    ssc_data_set_matrix(data, "sf_hdr_wallthicks", p_sf_hdr_wallthicks, 1, 1);
    ssc_number_t p_sf_hdr_lengths[1] = {-1};
    ssc_data_set_matrix(data, "sf_hdr_lengths", p_sf_hdr_lengths, 1, 1);
    ssc_data_set_number(data, "tanks_in_parallel", 1);
    ssc_data_set_number(data, "has_hot_tank_bypass", 0);
    ssc_data_set_number(data, "T_tank_hot_inlet_min", 400);
    ssc_data_set_number(data, "tes_pump_coef", 0.14999999999999999);
    ssc_data_set_number(data, "V_tes_des", 1.8500000000000001);
    ssc_data_set_number(data, "custom_tes_p_loss", 0);
    ssc_number_t p_k_tes_loss_coeffs[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_matrix(data, "k_tes_loss_coeffs", p_k_tes_loss_coeffs, 1, 11);
    ssc_data_set_number(data, "custom_tes_pipe_sizes", 0);
    ssc_number_t p_tes_diams[1] = {-1};
    ssc_data_set_matrix(data, "tes_diams", p_tes_diams, 1, 1);
    ssc_number_t p_tes_wallthicks[1] = {-1};
    ssc_data_set_matrix(data, "tes_wallthicks", p_tes_wallthicks, 1, 1);
    ssc_number_t p_tes_lengths[11] = {0, 90, 100, 120, 0, 0, 0, 0, 80, 120, 80};
    ssc_data_set_matrix(data, "tes_lengths", p_tes_lengths, 1, 11);
    ssc_data_set_number(data, "DP_SGS", 0);
    ssc_data_set_number(data, "adjust:constant", 4);
}

/**
*  Default data for the PPA single owner (utility) run that can be further modified
*/
void trough_physical_single_owner_default(ssc_data_t &data) {
    ssc_data_set_number(data, "analysis_period", 25);
    ssc_number_t p_federal_tax_rate[1] = {21};
    ssc_data_set_array(data, "federal_tax_rate", p_federal_tax_rate, 1);
    ssc_number_t p_state_tax_rate[1] = {7};
    ssc_data_set_array(data, "state_tax_rate", p_state_tax_rate, 1);
    ssc_data_set_number(data, "property_tax_rate", 0);
    ssc_data_set_number(data, "prop_tax_cost_assessed_percent", 100);
    ssc_data_set_number(data, "prop_tax_assessed_decline", 0);
    ssc_data_set_number(data, "real_discount_rate", 6.4000000953674316);
    ssc_data_set_number(data, "inflation_rate", 2.5);
    ssc_data_set_number(data, "insurance_rate", 0.5);
    ssc_data_set_number(data, "system_capacity", 99899.9921875);
    ssc_number_t p_om_fixed[1] = {0};
    ssc_data_set_array(data, "om_fixed", p_om_fixed, 1);
    ssc_data_set_number(data, "om_fixed_escal", 0);
    ssc_number_t p_om_production[1] = {4};
    ssc_data_set_array(data, "om_production", p_om_production, 1);
    ssc_data_set_number(data, "om_production_escal", 0);
    ssc_number_t p_om_capacity[1] = {66};
    ssc_data_set_array(data, "om_capacity", p_om_capacity, 1);
    ssc_data_set_number(data, "om_capacity_escal", 0);
    ssc_number_t p_om_fuel_cost[1] = {0};
    ssc_data_set_array(data, "om_fuel_cost", p_om_fuel_cost, 1);
    ssc_data_set_number(data, "om_fuel_cost_escal", 0);
    ssc_number_t p_om_replacement_cost1[1] = {0};
    ssc_data_set_array(data, "om_replacement_cost1", p_om_replacement_cost1, 1);
    ssc_data_set_number(data, "om_replacement_cost_escal", 0);
    ssc_data_set_number(data, "itc_fed_amount", 0);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_fed", 1);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_sta", 1);
    ssc_data_set_number(data, "itc_sta_amount", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "itc_fed_percent", 30);
    ssc_data_set_number(data, "itc_fed_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "itc_fed_percent_deprbas_fed", 1);
    ssc_data_set_number(data, "itc_fed_percent_deprbas_sta", 1);
    ssc_data_set_number(data, "itc_sta_percent", 0);
    ssc_data_set_number(data, "itc_sta_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "itc_sta_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "itc_sta_percent_deprbas_sta", 0);
    ssc_number_t p_ptc_fed_amount[1] = {0};
    ssc_data_set_array(data, "ptc_fed_amount", p_ptc_fed_amount, 1);
    ssc_data_set_number(data, "ptc_fed_term", 10);
    ssc_data_set_number(data, "ptc_fed_escal", 0);
    ssc_number_t p_ptc_sta_amount[1] = {0};
    ssc_data_set_array(data, "ptc_sta_amount", p_ptc_sta_amount, 1);
    ssc_data_set_number(data, "ptc_sta_term", 10);
    ssc_data_set_number(data, "ptc_sta_escal", 0);
    ssc_data_set_number(data, "ibi_fed_amount", 0);
    ssc_data_set_number(data, "ibi_fed_amount_tax_fed", 1);
    ssc_data_set_number(data, "ibi_fed_amount_tax_sta", 1);
    ssc_data_set_number(data, "ibi_fed_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_fed_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_sta_amount", 0);
    ssc_data_set_number(data, "ibi_sta_amount_tax_fed", 1);
    ssc_data_set_number(data, "ibi_sta_amount_tax_sta", 1);
    ssc_data_set_number(data, "ibi_sta_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_sta_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_uti_amount", 0);
    ssc_data_set_number(data, "ibi_uti_amount_tax_fed", 1);
    ssc_data_set_number(data, "ibi_uti_amount_tax_sta", 1);
    ssc_data_set_number(data, "ibi_uti_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_uti_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_oth_amount", 0);
    ssc_data_set_number(data, "ibi_oth_amount_tax_fed", 1);
    ssc_data_set_number(data, "ibi_oth_amount_tax_sta", 1);
    ssc_data_set_number(data, "ibi_oth_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_oth_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_fed_percent", 0);
    ssc_data_set_number(data, "ibi_fed_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "ibi_fed_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_fed_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_fed_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_fed_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_sta_percent", 0);
    ssc_data_set_number(data, "ibi_sta_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "ibi_sta_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_sta_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_sta_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_sta_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_uti_percent", 0);
    ssc_data_set_number(data, "ibi_uti_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "ibi_uti_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_uti_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_uti_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_uti_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_oth_percent", 0);
    ssc_data_set_number(data, "ibi_oth_percent_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "ibi_oth_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_oth_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_oth_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_oth_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_fed_amount", 0);
    ssc_data_set_number(data, "cbi_fed_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "cbi_fed_tax_fed", 1);
    ssc_data_set_number(data, "cbi_fed_tax_sta", 1);
    ssc_data_set_number(data, "cbi_fed_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_fed_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_sta_amount", 0);
    ssc_data_set_number(data, "cbi_sta_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "cbi_sta_tax_fed", 1);
    ssc_data_set_number(data, "cbi_sta_tax_sta", 1);
    ssc_data_set_number(data, "cbi_sta_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_sta_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_uti_amount", 0);
    ssc_data_set_number(data, "cbi_uti_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "cbi_uti_tax_fed", 1);
    ssc_data_set_number(data, "cbi_uti_tax_sta", 1);
    ssc_data_set_number(data, "cbi_uti_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_uti_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_oth_amount", 0);
    ssc_data_set_number(data, "cbi_oth_maxvalue", 9.9999996802856925e+37);
    ssc_data_set_number(data, "cbi_oth_tax_fed", 1);
    ssc_data_set_number(data, "cbi_oth_tax_sta", 1);
    ssc_data_set_number(data, "cbi_oth_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_oth_deprbas_sta", 0);
    ssc_number_t p_pbi_fed_amount[1] = {0};
    ssc_data_set_array(data, "pbi_fed_amount", p_pbi_fed_amount, 1);
    ssc_data_set_number(data, "pbi_fed_term", 0);
    ssc_data_set_number(data, "pbi_fed_escal", 0);
    ssc_data_set_number(data, "pbi_fed_tax_fed", 1);
    ssc_data_set_number(data, "pbi_fed_tax_sta", 1);
    ssc_number_t p_pbi_sta_amount[1] = {0};
    ssc_data_set_array(data, "pbi_sta_amount", p_pbi_sta_amount, 1);
    ssc_data_set_number(data, "pbi_sta_term", 0);
    ssc_data_set_number(data, "pbi_sta_escal", 0);
    ssc_data_set_number(data, "pbi_sta_tax_fed", 1);
    ssc_data_set_number(data, "pbi_sta_tax_sta", 1);
    ssc_number_t p_pbi_uti_amount[1] = {0};
    ssc_data_set_array(data, "pbi_uti_amount", p_pbi_uti_amount, 1);
    ssc_data_set_number(data, "pbi_uti_term", 0);
    ssc_data_set_number(data, "pbi_uti_escal", 0);
    ssc_data_set_number(data, "pbi_uti_tax_fed", 1);
    ssc_data_set_number(data, "pbi_uti_tax_sta", 1);
    ssc_number_t p_pbi_oth_amount[1] = {0};
    ssc_data_set_array(data, "pbi_oth_amount", p_pbi_oth_amount, 1);
    ssc_data_set_number(data, "pbi_oth_term", 0);
    ssc_data_set_number(data, "pbi_oth_escal", 0);
    ssc_data_set_number(data, "pbi_oth_tax_fed", 1);
    ssc_data_set_number(data, "pbi_oth_tax_sta", 1);
    ssc_number_t p_degradation[1] = {0};
    ssc_data_set_array(data, "degradation", p_degradation, 1);
    ssc_number_t p_roe_input[1] = {0};
    ssc_data_set_array(data, "roe_input", p_roe_input, 1);
    ssc_data_set_number(data, "loan_moratorium", 0);
    ssc_data_set_number(data, "system_use_recapitalization", 0);
    ssc_data_set_number(data, "system_use_lifetime_output", 0);
    ssc_data_set_number(data, "total_installed_cost", 562201472);
    ssc_data_set_number(data, "reserves_interest", 1.75);
    ssc_data_set_number(data, "equip1_reserve_cost", 0);
    ssc_data_set_number(data, "equip1_reserve_freq", 12);
    ssc_data_set_number(data, "equip2_reserve_cost", 0);
    ssc_data_set_number(data, "equip2_reserve_freq", 15);
    ssc_data_set_number(data, "equip3_reserve_cost", 0);
    ssc_data_set_number(data, "equip3_reserve_freq", 3);
    ssc_data_set_number(data, "equip_reserve_depr_sta", 0);
    ssc_data_set_number(data, "equip_reserve_depr_fed", 0);
    ssc_data_set_number(data, "salvage_percentage", 0);
    ssc_data_set_number(data, "ppa_soln_mode", 0);
    ssc_number_t p_ppa_price_input[1] = {0.13};
    ssc_data_set_array(data, "ppa_price_input", p_ppa_price_input, 1);
    ssc_data_set_number(data, "cp_capacity_payment_esc", 0);
    ssc_data_set_number(data, "cp_capacity_payment_type", 0);
    ssc_data_set_number(data, "cp_system_nameplate", 0);
    ssc_data_set_number(data, "cp_battery_nameplate", 0);
    ssc_data_set_array(data, "cp_capacity_credit_percent", p_ppa_price_input, 1);
    ssc_data_set_array(data, "cp_capacity_payment_amount", p_ppa_price_input, 1);
    ssc_data_set_number(data, "ppa_escalation", 1);
    ssc_data_set_number(data, "construction_financing_cost", 28110074);
    ssc_data_set_number(data, "term_tenor", 18);
    ssc_data_set_number(data, "term_int_rate", 7);
    ssc_data_set_number(data, "dscr", 1.2999999523162842);
    ssc_data_set_number(data, "dscr_reserve_months", 6);
    ssc_data_set_number(data, "debt_percent", 50);
    ssc_data_set_number(data, "debt_option", 1);
    ssc_data_set_number(data, "payment_option", 0);
    ssc_data_set_number(data, "cost_debt_closing", 450000);
    ssc_data_set_number(data, "cost_debt_fee", 2.75);
    ssc_data_set_number(data, "months_working_reserve", 6);
    ssc_data_set_number(data, "months_receivables_reserve", 0);
    ssc_data_set_number(data, "cost_other_financing", 0);
    ssc_data_set_number(data, "flip_target_percent", 11);
    ssc_data_set_number(data, "flip_target_year", 20);
    ssc_data_set_number(data, "depr_alloc_macrs_5_percent", 90);
    ssc_data_set_number(data, "depr_alloc_macrs_15_percent", 1.5);
    ssc_data_set_number(data, "depr_alloc_sl_5_percent", 0);
    ssc_data_set_number(data, "depr_alloc_sl_15_percent", 2.5);
    ssc_data_set_number(data, "depr_alloc_sl_20_percent", 3);
    ssc_data_set_number(data, "depr_alloc_sl_39_percent", 0);
    ssc_data_set_number(data, "depr_alloc_custom_percent", 0);
    ssc_number_t p_depr_custom_schedule[1] = {0};
    ssc_data_set_array(data, "depr_custom_schedule", p_depr_custom_schedule, 1);
    ssc_data_set_number(data, "depr_bonus_sta", 0);
    ssc_data_set_number(data, "depr_bonus_sta_macrs_5", 1);
    ssc_data_set_number(data, "depr_bonus_sta_macrs_15", 1);
    ssc_data_set_number(data, "depr_bonus_sta_sl_5", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_15", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_20", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_39", 0);
    ssc_data_set_number(data, "depr_bonus_sta_custom", 0);
    ssc_data_set_number(data, "depr_bonus_fed", 0);
    ssc_data_set_number(data, "depr_bonus_fed_macrs_5", 1);
    ssc_data_set_number(data, "depr_bonus_fed_macrs_15", 1);
    ssc_data_set_number(data, "depr_bonus_fed_sl_5", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_15", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_20", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_39", 0);
    ssc_data_set_number(data, "depr_bonus_fed_custom", 0);
    ssc_data_set_number(data, "depr_itc_sta_macrs_5", 1);
    ssc_data_set_number(data, "depr_itc_sta_macrs_15", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_5", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_15", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_20", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_39", 0);
    ssc_data_set_number(data, "depr_itc_sta_custom", 0);
    ssc_data_set_number(data, "depr_itc_fed_macrs_5", 1);
    ssc_data_set_number(data, "depr_itc_fed_macrs_15", 0);
    ssc_data_set_number(data, "depr_itc_fed_sl_5", 0);
    ssc_data_set_number(data, "depr_itc_fed_sl_15", 0);
    ssc_data_set_number(data, "depr_itc_fed_sl_20", 0);
    ssc_data_set_number(data, "depr_itc_fed_sl_39", 0);
    ssc_data_set_number(data, "depr_itc_fed_custom", 0);
    ssc_data_set_number(data, "pbi_fed_for_ds", 0);
    ssc_data_set_number(data, "pbi_sta_for_ds", 0);
    ssc_data_set_number(data, "pbi_uti_for_ds", 0);
    ssc_data_set_number(data, "pbi_oth_for_ds", 0);
    ssc_data_set_number(data, "depr_stabas_method", 1);
    ssc_data_set_number(data, "depr_fedbas_method", 1);
}

///**
//*  Default data for iph_to_lcoefcr run that can be further modified
//*/
//void convert_and_adjust_fixed_charge(ssc_data_t &data)
//{
//    ssc_data_set_number(data, "electricity_rate", 0.059999998658895493);
//    ssc_data_set_number(data, "fixed_operating_cost", 103758.203125);
//}
//
///**
//*  Default data for lcoefcr run that can be further modified
//*/
//void fixed_charge_rate_default(ssc_data_t &data)
//{
//    ssc_data_set_number(data, "capital_cost", 7263074);
//    ssc_data_set_number(data, "variable_operating_cost", 0.0010000000474974513);
//    ssc_data_set_number(data, "fixed_charge_rate", 0.10807877779006958);
//}

#endif
