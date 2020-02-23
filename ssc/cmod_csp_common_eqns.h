#ifndef _CMOD_CSP_COMMON_EQNS_H_
#define _CMOD_CSP_COMMON_EQNS_H_

#include "sscapi.h"
#include "../shared/lib_util.h"
#include "htf_props.h"


HTFProperties GetHtfProperties(int fluid_number, const util::matrix_t<double> &specified_fluid_properties = NULL);       // [-]



// Originally from 'MSPT System Design' UI Form
double Nameplate(double P_ref /*MWe*/, double gross_net_conversion_factor /*-*/);       // [MWe]

double Q_pb_design(double P_ref /*MWe*/, double design_eff /*-*/);      // [MWt]

double Q_rec_des(double solarm /*-*/, double q_pb_design /*MWt*/);      // [MWt]

double Tshours_sf(double tshours /*hr*/, double solarm /*-*/);          // [hr]



// Originally from 'Tower SolarPilot Solar Field' UI Form
double Land_max_calc(double land_max /*-*/, double h_tower /*m*/);      // [m]

double N_hel(const util::matrix_t<ssc_number_t> &helio_positions /*m*/);      // [-]

double Csp_pt_sf_heliostat_area(double helio_height /*m*/, double helio_width /*m*/, double dens_mirror /*-*/);     // [m2]

double Csp_pt_sf_total_reflective_area(int n_hel /*-*/, double csp_pt_sf_heliostat_area /*m2*/);     // [m2]

double Land_min_calc(double land_min /*-*/, double h_tower /*m*/);      // [m]

double Csp_pt_sf_total_land_area(double csp_pt_sf_fixed_land_area /*acres*/, double land_area_base /*acres*/,
    double csp_pt_sf_land_overhead_factor /*-*/);       // [acres]

double A_sf_UI(double helio_width /*m*/, double helio_height /*m*/, double dens_mirror /*-*/, int n_hel /*-*/);  // [m2]

double Helio_area_tot(double A_sf_UI /*m2*/);     // [m2]

double Csp_pt_sf_tower_height(double h_tower /*m*/);        // [m]

double C_atm_info(const util::matrix_t<ssc_number_t> &helio_positions /*m*/,
    double c_atm_0 /*-*/, double c_atm_1 /*-*/, double c_atm_2 /*-*/, double c_atm_3 /*-*/, double h_tower /*m*/);  // [%]

double Error_equiv(double helio_optical_error_mrad /*mrad*/);       // [mrad]

int Is_optimize(int override_opt /*-*/);      // [-]

double Field_model_type(int is_optimize /*-*/, int override_layout /*-*/);      // [-]

double Q_design(double Q_rec_des /*MWt*/);      // [MWt]

double Dni_des_calc(double dni_des /*W/m2*/);       // [W/m2]

int Opt_algorithm();        // [-]

double Opt_flux_penalty();  // [-]



// Originally from 'MSPT Receiver' UI Form
double Csp_pt_rec_cav_lip_height();     // [m?]

double Csp_pt_rec_cav_panel_height();   // [m?]

double Csp_pt_rec_max_flow_to_rec(double csp_pt_rec_max_oper_frac /*-*/, double Q_rec_des /*MWt*/,
    double csp_pt_rec_htf_c_avg /*kJ/kg-K*/, double T_htf_hot_des /*C*/, double T_htf_cold_des /*C*/);      // [kg/s]

double Csp_pt_rec_htf_t_avg(double T_htf_cold_des /*C*/, double T_htf_hot_des /*C*/);       // [C]

double Csp_pt_rec_cav_ap_height(double rec_d_spec /*m*/, double csp_pt_rec_cav_ap_hw_ratio /*-*/);      // [m]

double Csp_pt_rec_htf_c_avg(double csp_pt_rec_htf_t_avg /*C*/, int rec_htf /*-*/,
    const util::matrix_t<ssc_number_t> &field_fl_props = NULL /*-*/);      // [kJ/kg-K]

double Rec_aspect(double D_rec /*m*/, double rec_height /*m*/);     // [-]

double Piping_length(double h_tower /*m*/, double piping_length_mult /*-*/, double piping_length_const /*m*/);      // [m]

double Piping_loss_tot(double piping_length /*m*/, double piping_loss /*Wt/m*/);        // [kWt]


#endif