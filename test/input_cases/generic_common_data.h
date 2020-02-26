#ifndef _GENERIC_COMMON_DATA_H_
#define _GENERIC_COMMON_DATA_H_

#include <stdio.h>
#include "code_generator_utilities.h"

namespace generictest {
    char load_profile_path_60min[256];
    char load_profile_path_30min[256];
    char gen_path_60min[256];
    char gen_path_30min[256];
    char batt_dispatch_path_30min[256];
    char batt_dispatch_path_60min[256];
    char dispatch_factors_unused[256];
    char sell_rate_unused[256];
    char temperature_path[256];
    char temperature_path_30min[256];


    int n1 = sprintf(load_profile_path_60min, "%s/test/input_cases/generic_system_data/load_60min.csv", SSCDIR);
    int n2 = sprintf(load_profile_path_30min, "%s/test/input_cases/generic_system_data/load_30min.csv", SSCDIR);
    int n3 = sprintf(gen_path_60min, "%s/test/input_cases/generic_system_data/energy_output_array_60min.csv", SSCDIR);
    int n4 = sprintf(gen_path_30min, "%s/test/input_cases/generic_system_data/energy_output_array_30min.csv", SSCDIR);
    int n5 = sprintf(batt_dispatch_path_30min, "%s/test/input_cases/generic_system_data/batt_custom_dispatch_30min.csv",
                     SSCDIR);
    int n6 = sprintf(batt_dispatch_path_60min, "%s/test/input_cases/generic_system_data/batt_custom_dispatch_60min.csv",
                     SSCDIR);
    int n7 = sprintf(dispatch_factors_unused, "%s/test/input_cases/generic_system_data/dispatch_factors_ts.csv",
                     SSCDIR);
    int n8 = sprintf(sell_rate_unused, "%s/test/input_cases/generic_system_data/ur_ts_sell_rate.csv", SSCDIR);
    int n9 = sprintf(temperature_path, "%s/test/input_cases/battery_data/batt_room_temperature_celsius_60min.csv",
                     SSCDIR);
    int n10 = sprintf(temperature_path_30min,
                      "%s/test/input_cases/battery_data/batt_room_temperature_celsius_30min.csv", SSCDIR);
}


void generic_singleowner_battery_60min(ssc_data_t &data) {
    ssc_data_set_number(data, "spec_mode", 1);
    ssc_data_set_number(data, "derate", 0);
    ssc_data_set_number(data, "system_capacity", 208842);
    ssc_data_set_number(data, "user_capacity_factor", 43.599998474121094);
    ssc_data_set_number(data, "heat_rate", 0);
    ssc_data_set_number(data, "conv_eff", 0);
    set_array(data, "energy_output_array", generictest::gen_path_60min, 8760);
    ssc_data_set_number(data, "system_use_lifetime_output", 0);
    ssc_data_set_number(data, "analysis_period", 25);
    ssc_number_t p_generic_degradation[1] = {0};
    ssc_data_set_array(data, "generic_degradation", p_generic_degradation, 1);
    ssc_data_set_number(data, "adjust:constant", 0);

    ssc_data_set_number(data, "en_batt", 1);
    ssc_data_set_number(data, "batt_replacement_option", 0);
    ssc_data_set_number(data, "batt_chem", 1);
    ssc_data_set_number(data, "batt_ac_or_dc", 1);
    ssc_data_set_number(data, "batt_dc_dc_efficiency", 99);
    ssc_data_set_number(data, "batt_dc_ac_efficiency", 96);
    ssc_data_set_number(data, "batt_ac_dc_efficiency", 96);
    ssc_data_set_number(data, "batt_meter_position", 1);
    ssc_number_t p_batt_losses[1] = {0};
    ssc_data_set_array(data, "batt_losses", p_batt_losses, 1);
    ssc_number_t p_batt_losses_charging[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_array(data, "batt_losses_charging", p_batt_losses_charging, 12);
    ssc_number_t p_batt_losses_discharging[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_array(data, "batt_losses_discharging", p_batt_losses_discharging, 12);
    ssc_number_t p_batt_losses_idle[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ssc_data_set_array(data, "batt_losses_idle", p_batt_losses_idle, 12);
    ssc_data_set_number(data, "batt_loss_choice", 0);
    ssc_data_set_number(data, "batt_current_choice", 1);
    ssc_data_set_number(data, "batt_computed_strings", 1733583);
    ssc_data_set_number(data, "batt_computed_series", 152);
    ssc_data_set_number(data, "batt_computed_bank_capacity", 2000000);
    ssc_data_set_number(data, "batt_current_charge_max", 1993620.375);
    ssc_data_set_number(data, "batt_current_discharge_max", 1993620.375);
    ssc_data_set_number(data, "batt_power_charge_max", 1000000);
    ssc_data_set_number(data, "batt_power_discharge_max", 1000000);
    ssc_data_set_number(data, "batt_inverter_efficiency_cutoff", 90);
    ssc_data_set_number(data, "batt_power_charge_max_kwdc", 1000000);
    ssc_data_set_number(data, "batt_power_discharge_max_kwdc", 1000000);
    ssc_data_set_number(data, "batt_power_charge_max_kwac", 1000000);
    ssc_data_set_number(data, "batt_power_discharge_max_kwac", 1000000);
    ssc_data_set_number(data, "batt_voltage_choice", 0);
    ssc_data_set_number(data, "batt_Vfull", 3.5999999046325684);
    ssc_data_set_number(data, "batt_Vexp", 3.4000000953674316);
    ssc_data_set_number(data, "batt_Vnom", 3.2999999523162842);
    ssc_data_set_number(data, "batt_Vnom_default", 3.2999999523162842);
    ssc_data_set_number(data, "batt_Qfull", 2.2999999523162842);
    ssc_data_set_number(data, "batt_Qfull_flow", 3987240.75);
    ssc_data_set_number(data, "batt_Qexp", 0.049910001456737518);
    ssc_data_set_number(data, "batt_Qnom", 2.0446999073028564);
    ssc_data_set_number(data, "batt_C_rate", 0.43000000715255737);
    ssc_data_set_number(data, "batt_resistance", 0.0010000000474974513);
    ssc_number_t p_batt_voltage_matrix[2] = {0, 0};
    ssc_data_set_matrix(data, "batt_voltage_matrix", p_batt_voltage_matrix, 1, 2);
    ssc_data_set_number(data, "LeadAcid_q20_computed", 3987240.75);
    ssc_data_set_number(data, "LeadAcid_q10_computed", 3708134);
    ssc_data_set_number(data, "LeadAcid_qn_computed", 2392344.5);
    ssc_data_set_number(data, "LeadAcid_tn", 1);
    ssc_data_set_number(data, "batt_initial_SOC", 50);
    ssc_data_set_number(data, "batt_minimum_SOC", 15);
    ssc_data_set_number(data, "batt_maximum_SOC", 95);
    ssc_data_set_number(data, "batt_minimum_modetime", 10);
    ssc_number_t p_batt_lifetime_matrix[18] = {20, 0, 100, 20, 2500, 98, 20, 5000, 95, 80, 0, 100, 80, 500, 98, 80,
                                               1000, 95};
    ssc_data_set_matrix(data, "batt_lifetime_matrix", p_batt_lifetime_matrix, 6, 3);
    ssc_data_set_number(data, "batt_calendar_choice", 1);
    ssc_number_t p_batt_calendar_lifetime_matrix[6] = {0, 100, 3650, 80, 7300, 50};
    ssc_data_set_matrix(data, "batt_calendar_lifetime_matrix", p_batt_calendar_lifetime_matrix, 3, 2);
    ssc_data_set_number(data, "batt_calendar_q0", 1.0199999809265137);
    ssc_data_set_number(data, "batt_calendar_a", 0.0026599999982863665);
    ssc_data_set_number(data, "batt_calendar_b", -7280);
    ssc_data_set_number(data, "batt_calendar_c", 930);
    ssc_data_set_number(data, "batt_replacement_capacity", 0);
    ssc_number_t p_batt_replacement_schedule[1] = {0};
    ssc_data_set_array(data, "batt_replacement_schedule", p_batt_replacement_schedule, 1);
    ssc_number_t p_replacement_cost[1] = {600};
    ssc_data_set_array(data, "om_replacement_cost1", p_replacement_cost, 1);
    ssc_data_set_number(data, "batt_mass", 21489202);
    ssc_data_set_number(data, "batt_length", 21.196117401123047);
    ssc_data_set_number(data, "batt_width", 21.196117401123047);
    ssc_data_set_number(data, "batt_height", 21.196117401123047);
    ssc_data_set_number(data, "batt_Cp", 1004);
    ssc_data_set_number(data, "batt_h_to_ambient", 5);
    set_array(data, "batt_room_temperature_celsius", generictest::temperature_path, 8760);
    ssc_number_t p_cap_vs_temp[8] = {-10, 60, 0, 80, 25, 100, 40, 100};
    ssc_data_set_matrix(data, "cap_vs_temp", p_cap_vs_temp, 4, 2);
    ssc_number_t p_dispatch_manual_charge[6] = {1, 1, 1, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_charge", p_dispatch_manual_charge, 6);
    ssc_number_t p_dispatch_manual_discharge[6] = {0, 0, 1, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_discharge", p_dispatch_manual_discharge, 6);
    ssc_number_t p_dispatch_manual_gridcharge[6] = {0, 0, 0, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_gridcharge", p_dispatch_manual_gridcharge, 6);
    ssc_number_t p_dispatch_manual_percent_discharge[2] = {25, 0};
    ssc_data_set_array(data, "dispatch_manual_percent_discharge", p_dispatch_manual_percent_discharge, 2);
    ssc_number_t p_dispatch_manual_percent_gridcharge[1] = {0};
    ssc_data_set_array(data, "dispatch_manual_percent_gridcharge", p_dispatch_manual_percent_gridcharge, 1);
    ssc_number_t p_dispatch_manual_sched[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1,
                                                 1};
    ssc_data_set_matrix(data, "dispatch_manual_sched", p_dispatch_manual_sched, 12, 24);
    ssc_number_t p_dispatch_manual_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3,
                                                         3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3,
                                                         3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "dispatch_manual_sched_weekend", p_dispatch_manual_sched_weekend, 12, 24);
    set_array(data, "batt_custom_dispatch", generictest::batt_dispatch_path_60min, 8760);
    ssc_data_set_number(data, "batt_dispatch_choice", 3);
    ssc_number_t p_batt_pv_clipping_forecast[1] = {0};
    ssc_data_set_array(data, "batt_pv_clipping_forecast", p_batt_pv_clipping_forecast, 1);
    ssc_number_t p_batt_pv_dc_forecast[1] = {0};
    ssc_data_set_array(data, "batt_pv_dc_forecast", p_batt_pv_dc_forecast, 1);
    ssc_data_set_number(data, "batt_dispatch_auto_can_gridcharge", 0);
    ssc_data_set_number(data, "batt_dispatch_auto_can_charge", 1);
    ssc_data_set_number(data, "batt_dispatch_auto_can_clipcharge", 1);
    ssc_data_set_number(data, "batt_auto_gridcharge_max_daily", 100);
    ssc_data_set_number(data, "batt_look_ahead_hours", 18);
    ssc_data_set_number(data, "batt_dispatch_update_frequency_hours", 1);
    ssc_data_set_number(data, "batt_cycle_cost_choice", 0);
    ssc_data_set_number(data, "batt_cycle_cost", 0.10000000149011612);
    ssc_data_set_number(data, "en_electricity_rates", 0);
    ssc_number_t p_ur_ec_sched_weekday[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_ec_sched_weekday", p_ur_ec_sched_weekday, 12, 24);
    ssc_number_t p_ur_ec_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_ec_sched_weekend", p_ur_ec_sched_weekend, 12, 24);
    ssc_number_t p_ur_ec_tou_mat[30] = {1, 1, 9.9999996802856925e+37, 0, 0.094169996678829193, 0, 2, 1, 400, 0,
                                        0.096869997680187225, 0, 2, 2, 800, 0, 0.13817000389099121, 0, 2, 3, 3000, 0,
                                        0.16166999936103821, 0, 2, 4, 9.9999996802856925e+37, 0, 0.17257000505924225,
                                        0};
    ssc_data_set_matrix(data, "ur_ec_tou_mat", p_ur_ec_tou_mat, 5, 6);
    ssc_data_set_number(data, "ur_en_ts_sell_rate", 0);
    ssc_number_t p_ur_ts_buy_rate[1] = {0};
    ssc_data_set_array(data, "ur_ts_buy_rate", p_ur_ts_buy_rate, 1);
    ssc_number_t p_ppa_price_input[1] = {0};
    ssc_data_set_array(data, "ppa_price_input", p_ppa_price_input, 1);
    ssc_data_set_number(data, "cp_capacity_payment_esc", 0);
    ssc_data_set_number(data, "cp_capacity_payment_type", 0);
    ssc_data_set_number(data, "cp_system_nameplate", 0);
    ssc_data_set_number(data, "cp_battery_nameplate", 0);
    ssc_data_set_array(data, "cp_capacity_credit_percent", p_ppa_price_input, 1);
    ssc_data_set_array(data, "cp_capacity_payment_amount", p_ppa_price_input, 1);
    ssc_number_t p_dispatch_tod_factors[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_array(data, "dispatch_tod_factors", p_dispatch_tod_factors, 9);
    ssc_number_t p_dispatch_sched_weekday[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "dispatch_sched_weekday", p_dispatch_sched_weekday, 12, 24);
    ssc_number_t p_dispatch_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "dispatch_sched_weekend", p_dispatch_sched_weekend, 12, 24);

    ssc_number_t p_federal_tax_rate[1] = {21};
    ssc_data_set_array(data, "federal_tax_rate", p_federal_tax_rate, 1);
    ssc_number_t p_state_tax_rate[1] = {0};
    ssc_data_set_array(data, "state_tax_rate", p_state_tax_rate, 1);
    ssc_data_set_number(data, "property_tax_rate", 1);
    ssc_data_set_number(data, "prop_tax_cost_assessed_percent", 100);
    ssc_data_set_number(data, "prop_tax_assessed_decline", 0);
    ssc_data_set_number(data, "real_discount_rate", 6.4000000953674316);
    ssc_data_set_number(data, "inflation_rate", 2.5);
    ssc_data_set_number(data, "insurance_rate", 1);
    ssc_number_t p_om_fixed[1] = {0};
    ssc_data_set_array(data, "om_fixed", p_om_fixed, 1);
    ssc_data_set_number(data, "om_fixed_escal", 0);
    ssc_number_t p_om_production[1] = {0};
    ssc_data_set_array(data, "om_production", p_om_production, 1);
    ssc_data_set_number(data, "om_production_escal", 0);
    ssc_number_t p_om_capacity[1] = {50};
    ssc_data_set_array(data, "om_capacity", p_om_capacity, 1);
    ssc_data_set_number(data, "om_capacity_escal", 0);
    ssc_number_t p_om_fuel_cost[1] = {0};
    ssc_data_set_array(data, "om_fuel_cost", p_om_fuel_cost, 1);
    ssc_data_set_number(data, "om_fuel_cost_escal", 0);
    ssc_data_set_number(data, "itc_fed_amount", 0);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_fed", 1);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_sta", 1);
    ssc_data_set_number(data, "itc_sta_amount", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "itc_fed_percent", 30);
    ssc_data_set_number(data, "itc_fed_percent_maxvalue", 1);
    ssc_data_set_number(data, "itc_fed_percent_deprbas_fed", 1);
    ssc_data_set_number(data, "itc_fed_percent_deprbas_sta", 1);
    ssc_data_set_number(data, "itc_sta_percent", 0);
    ssc_data_set_number(data, "itc_sta_percent_maxvalue", 1);
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
    ssc_data_set_number(data, "ibi_fed_percent_maxvalue", 0);
    ssc_data_set_number(data, "ibi_fed_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_fed_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_fed_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_fed_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_sta_percent", 0);
    ssc_data_set_number(data, "ibi_sta_percent_maxvalue", 0);
    ssc_data_set_number(data, "ibi_sta_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_sta_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_sta_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_sta_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_uti_percent", 0);
    ssc_data_set_number(data, "ibi_uti_percent_maxvalue", 0);
    ssc_data_set_number(data, "ibi_uti_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_uti_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_uti_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_uti_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "ibi_oth_percent", 0);
    ssc_data_set_number(data, "ibi_oth_percent_maxvalue", 0);
    ssc_data_set_number(data, "ibi_oth_percent_tax_fed", 1);
    ssc_data_set_number(data, "ibi_oth_percent_tax_sta", 1);
    ssc_data_set_number(data, "ibi_oth_percent_deprbas_fed", 0);
    ssc_data_set_number(data, "ibi_oth_percent_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_fed_amount", 0);
    ssc_data_set_number(data, "cbi_fed_maxvalue", 0);
    ssc_data_set_number(data, "cbi_fed_tax_fed", 1);
    ssc_data_set_number(data, "cbi_fed_tax_sta", 1);
    ssc_data_set_number(data, "cbi_fed_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_fed_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_sta_amount", 0);
    ssc_data_set_number(data, "cbi_sta_maxvalue", 0);
    ssc_data_set_number(data, "cbi_sta_tax_fed", 1);
    ssc_data_set_number(data, "cbi_sta_tax_sta", 1);
    ssc_data_set_number(data, "cbi_sta_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_sta_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_uti_amount", 0);
    ssc_data_set_number(data, "cbi_uti_maxvalue", 0);
    ssc_data_set_number(data, "cbi_uti_tax_fed", 1);
    ssc_data_set_number(data, "cbi_uti_tax_sta", 1);
    ssc_data_set_number(data, "cbi_uti_deprbas_fed", 0);
    ssc_data_set_number(data, "cbi_uti_deprbas_sta", 0);
    ssc_data_set_number(data, "cbi_oth_amount", 0);
    ssc_data_set_number(data, "cbi_oth_maxvalue", 0);
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
    ssc_data_set_number(data, "ppa_multiplier_model", 0);
    set_array(data, "dispatch_factors_ts", generictest::dispatch_factors_unused, 8147);
    ssc_data_set_number(data, "dispatch_factor1", 1);
    ssc_data_set_number(data, "dispatch_factor2", 1);
    ssc_data_set_number(data, "dispatch_factor3", 1);
    ssc_data_set_number(data, "dispatch_factor4", 1);
    ssc_data_set_number(data, "dispatch_factor5", 1);
    ssc_data_set_number(data, "dispatch_factor6", 1);
    ssc_data_set_number(data, "dispatch_factor7", 1);
    ssc_data_set_number(data, "dispatch_factor8", 1);
    ssc_data_set_number(data, "dispatch_factor9", 1);
    ssc_data_set_number(data, "total_installed_cost", 1554456064);
    ssc_data_set_number(data, "reserves_interest", 1.75);
    ssc_data_set_number(data, "equip1_reserve_cost", 0);
    ssc_data_set_number(data, "equip1_reserve_freq", 0);
    ssc_data_set_number(data, "equip2_reserve_cost", 0);
    ssc_data_set_number(data, "equip2_reserve_freq", 0);
    ssc_data_set_number(data, "equip3_reserve_cost", 0);
    ssc_data_set_number(data, "equip3_reserve_freq", 0);
    ssc_data_set_number(data, "equip_reserve_depr_sta", 0);
    ssc_data_set_number(data, "equip_reserve_depr_fed", 0);
    ssc_data_set_number(data, "salvage_percentage", 0);
    ssc_data_set_number(data, "ppa_soln_mode", 0);
    ssc_data_set_number(data, "ppa_escalation", 1);
    ssc_data_set_number(data, "construction_financing_cost", 0);
    ssc_data_set_number(data, "term_tenor", 0);
    ssc_data_set_number(data, "term_int_rate", 0);
    ssc_data_set_number(data, "dscr", 0);
    ssc_data_set_number(data, "dscr_reserve_months", 0);
    ssc_data_set_number(data, "debt_percent", 50);
    ssc_data_set_number(data, "debt_option", 1);
    ssc_data_set_number(data, "payment_option", 0);
    ssc_data_set_number(data, "cost_debt_closing", 0);
    ssc_data_set_number(data, "cost_debt_fee", 0);
    ssc_data_set_number(data, "months_working_reserve", 6);
    ssc_data_set_number(data, "months_receivables_reserve", 0);
    ssc_data_set_number(data, "cost_other_financing", 0);
    ssc_data_set_number(data, "flip_target_percent", 10);
    ssc_data_set_number(data, "flip_target_year", 10);
    ssc_data_set_number(data, "depr_alloc_macrs_5_percent", 100);
    ssc_data_set_number(data, "depr_alloc_macrs_15_percent", 0);
    ssc_data_set_number(data, "depr_alloc_sl_5_percent", 0);
    ssc_data_set_number(data, "depr_alloc_sl_15_percent", 0);
    ssc_data_set_number(data, "depr_alloc_sl_20_percent", 0);
    ssc_data_set_number(data, "depr_alloc_sl_39_percent", 0);
    ssc_data_set_number(data, "depr_alloc_custom_percent", 0);
    ssc_number_t p_depr_custom_schedule[1] = {0};
    ssc_data_set_array(data, "depr_custom_schedule", p_depr_custom_schedule, 1);
    ssc_data_set_number(data, "depr_bonus_sta", 0);
    ssc_data_set_number(data, "depr_bonus_sta_macrs_5", 0);
    ssc_data_set_number(data, "depr_bonus_sta_macrs_15", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_5", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_15", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_20", 0);
    ssc_data_set_number(data, "depr_bonus_sta_sl_39", 0);
    ssc_data_set_number(data, "depr_bonus_sta_custom", 0);
    ssc_data_set_number(data, "depr_bonus_fed", 0);
    ssc_data_set_number(data, "depr_bonus_fed_macrs_5", 1);
    ssc_data_set_number(data, "depr_bonus_fed_macrs_15", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_5", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_15", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_20", 0);
    ssc_data_set_number(data, "depr_bonus_fed_sl_39", 0);
    ssc_data_set_number(data, "depr_bonus_fed_custom", 0);
    ssc_data_set_number(data, "depr_itc_sta_macrs_5", 0);
    ssc_data_set_number(data, "depr_itc_sta_macrs_15", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_5", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_15", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_20", 0);
    ssc_data_set_number(data, "depr_itc_sta_sl_39", 0);
    ssc_data_set_number(data, "depr_itc_sta_custom", 0);
    ssc_data_set_number(data, "depr_itc_fed_macrs_5", 0);
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
    ssc_data_set_number(data, "battery_per_kWh", 300);
    ssc_data_set_number(data, "batt_replacement_cost_escal", 0);
}

void generic_commerical_battery_60min(ssc_data_t &data) {
    ssc_data_set_number(data, "spec_mode", 1);
    ssc_data_set_number(data, "derate", 4);
    ssc_data_set_number(data, "system_capacity", 1.7090300321578979);
    ssc_data_set_number(data, "user_capacity_factor", 43.599998474121094);
    ssc_data_set_number(data, "heat_rate", 10);
    ssc_data_set_number(data, "conv_eff", 34.118049621582031);
    set_array(data, "energy_output_array", generictest::gen_path_60min, 8760);
    ssc_data_set_number(data, "system_use_lifetime_output", 0);
    ssc_data_set_number(data, "analysis_period", 25);
    ssc_number_t p_generic_degradation[1] = {0};
    ssc_data_set_array(data, "generic_degradation", p_generic_degradation, 1);
    ssc_data_set_number(data, "adjust:constant", 0);

    ssc_data_set_number(data, "en_batt", 1);
    set_array(data, "load", generictest::load_profile_path_60min, 8760);
    ssc_data_set_number(data, "batt_replacement_option", 0);
    ssc_data_set_number(data, "batt_chem", 1);
    ssc_data_set_number(data, "batt_ac_or_dc", 1);
    ssc_data_set_number(data, "batt_dc_dc_efficiency", 98);
    ssc_data_set_number(data, "batt_dc_ac_efficiency", 96);
    ssc_data_set_number(data, "batt_ac_dc_efficiency", 96);
    ssc_data_set_number(data, "batt_meter_position", 0);
    ssc_number_t p_batt_losses[1] = {0};
    ssc_data_set_array(data, "batt_losses", p_batt_losses, 1);
    ssc_number_t p_batt_losses_charging[1] = {0};
    ssc_data_set_array(data, "batt_losses_charging", p_batt_losses_charging, 1);
    ssc_number_t p_batt_losses_discharging[1] = {0};
    ssc_data_set_array(data, "batt_losses_discharging", p_batt_losses_discharging, 1);
    ssc_number_t p_batt_losses_idle[1] = {0};
    ssc_data_set_array(data, "batt_losses_idle", p_batt_losses_idle, 1);
    ssc_data_set_number(data, "batt_loss_choice", 0);
    ssc_data_set_number(data, "batt_current_choice", 1);
    ssc_data_set_number(data, "batt_computed_strings", 89);
    ssc_data_set_number(data, "batt_computed_series", 139);
    ssc_data_set_number(data, "batt_computed_bank_capacity", 100.20510101318359);
    ssc_data_set_number(data, "batt_current_charge_max", 100.125);
    ssc_data_set_number(data, "batt_current_discharge_max", 100.125);
    ssc_data_set_number(data, "batt_inverter_efficiency_cutoff", 90);
    ssc_data_set_number(data, "batt_power_charge_max_kwdc", 50.10255050659179);
    ssc_data_set_number(data, "batt_power_discharge_max_kwdc", 50.10255050659179);
    ssc_data_set_number(data, "batt_power_charge_max_kwac", 50.10255050659179);
    ssc_data_set_number(data, "batt_power_discharge_max_kwac", 50.10255050659179);
    ssc_data_set_number(data, "batt_voltage_choice", 0);
    ssc_data_set_number(data, "batt_Vfull", 4.0999999046325684);
    ssc_data_set_number(data, "batt_Vexp", 4.0500001907348633);
    ssc_data_set_number(data, "batt_Vnom", 3.4000000953674316);
    ssc_data_set_number(data, "batt_Vnom_default", 3.5999999046325684);
    ssc_data_set_number(data, "batt_Qfull", 2.25);
    ssc_data_set_number(data, "batt_Qfull_flow", 200.25);
    ssc_data_set_number(data, "batt_Qexp", 0.040049999952316284);
    ssc_data_set_number(data, "batt_Qnom", 2.0002501010894775);
    ssc_data_set_number(data, "batt_C_rate", 0.20000000298023224);
    ssc_data_set_number(data, "batt_resistance", 0.20000000298023224);
    ssc_number_t p_batt_voltage_matrix[12] = {0, 1.2000000476837158, 20, 1.1000000238418579, 40, 1.0499999523162842, 60,
                                              1, 80, 0.94999998807907104, 100, 0.5};
    ssc_data_set_matrix(data, "batt_voltage_matrix", p_batt_voltage_matrix, 6, 2);
    ssc_data_set_number(data, "LeadAcid_q20_computed", 200.25);
    ssc_data_set_number(data, "LeadAcid_q10_computed", 186.23249816894531);
    ssc_data_set_number(data, "LeadAcid_qn_computed", 120.15000152587891);
    ssc_data_set_number(data, "LeadAcid_tn", 1);
    ssc_data_set_number(data, "batt_initial_SOC", 50);
    ssc_data_set_number(data, "batt_minimum_SOC", 15);
    ssc_data_set_number(data, "batt_maximum_SOC", 95);
    ssc_data_set_number(data, "batt_minimum_modetime", 10);
    ssc_number_t p_batt_lifetime_matrix[18] = {20, 0, 100, 20, 5000, 80, 20, 10000, 60, 80, 0, 100, 80, 1000, 80, 80,
                                               2000, 60};
    ssc_data_set_matrix(data, "batt_lifetime_matrix", p_batt_lifetime_matrix, 6, 3);
    ssc_data_set_number(data, "batt_calendar_choice", 0);
    ssc_number_t p_batt_calendar_lifetime_matrix[6] = {0, 100, 3650, 80, 7300, 50};
    ssc_data_set_matrix(data, "batt_calendar_lifetime_matrix", p_batt_calendar_lifetime_matrix, 3, 2);
    ssc_data_set_number(data, "batt_calendar_q0", 1.0199999809265137);
    ssc_data_set_number(data, "batt_calendar_a", 0.0026599999982863665);
    ssc_data_set_number(data, "batt_calendar_b", -7280);
    ssc_data_set_number(data, "batt_calendar_c", 930);
    ssc_data_set_number(data, "batt_replacement_capacity", 0);
    ssc_number_t p_batt_replacement_schedule[1] = {0};
    ssc_data_set_array(data, "batt_replacement_schedule", p_batt_replacement_schedule, 1);
    ssc_number_t p_replacement_cost[1] = {600};
    ssc_data_set_array(data, "om_replacement_cost1", p_replacement_cost, 1);
    ssc_data_set_number(data, "batt_mass", 507.8046875);
    ssc_data_set_number(data, "batt_length", 0.58471626043319702);
    ssc_data_set_number(data, "batt_width", 0.58471626043319702);
    ssc_data_set_number(data, "batt_height", 0.58471626043319702);
    ssc_data_set_number(data, "batt_Cp", 4183);
    ssc_data_set_number(data, "batt_h_to_ambient", 5);
    set_array(data, "batt_room_temperature_celsius", generictest::temperature_path, 8760);
    ssc_number_t p_cap_vs_temp[8] = {-15, 65, 0, 85, 25, 100, 40, 104};
    ssc_data_set_matrix(data, "cap_vs_temp", p_cap_vs_temp, 4, 2);
    ssc_number_t p_dispatch_manual_charge[6] = {1, 1, 1, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_charge", p_dispatch_manual_charge, 6);
    ssc_number_t p_dispatch_manual_discharge[6] = {0, 0, 1, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_discharge", p_dispatch_manual_discharge, 6);
    ssc_number_t p_dispatch_manual_gridcharge[6] = {0, 1, 0, 0, 0, 0};
    ssc_data_set_array(data, "dispatch_manual_gridcharge", p_dispatch_manual_gridcharge, 6);
    ssc_number_t p_dispatch_manual_percent_discharge[2] = {25, 0};
    ssc_data_set_array(data, "dispatch_manual_percent_discharge", p_dispatch_manual_percent_discharge, 2);
    ssc_number_t p_dispatch_manual_percent_gridcharge[2] = {100, 0};
    ssc_data_set_array(data, "dispatch_manual_percent_gridcharge", p_dispatch_manual_percent_gridcharge, 2);
    ssc_number_t p_dispatch_manual_sched[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1,
                                                 1};
    ssc_data_set_matrix(data, "dispatch_manual_sched", p_dispatch_manual_sched, 12, 24);
    ssc_number_t p_dispatch_manual_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3,
                                                         3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3,
                                                         3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                                         1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "dispatch_manual_sched_weekend", p_dispatch_manual_sched_weekend, 12, 24);
    ssc_number_t p_batt_target_power[1] = {15};
    ssc_data_set_array(data, "batt_target_power", p_batt_target_power, 1);
    ssc_number_t p_batt_target_power_monthly[1] = {0};
    ssc_data_set_array(data, "batt_target_power_monthly", p_batt_target_power_monthly, 1);
    ssc_data_set_number(data, "batt_target_choice", 0);
    set_array(data, "batt_custom_dispatch", generictest::batt_dispatch_path_60min, 8760);
    ssc_data_set_number(data, "batt_dispatch_choice", 3);
    ssc_data_set_number(data, "batt_dispatch_auto_can_gridcharge", 0);
    ssc_data_set_number(data, "batt_dispatch_auto_can_charge", 1);
    ssc_number_t p_ur_ec_sched_weekday[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_ec_sched_weekday", p_ur_ec_sched_weekday, 12, 24);
    ssc_number_t p_ur_ec_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_ec_sched_weekend", p_ur_ec_sched_weekend, 12, 24);
    ssc_number_t p_ur_ec_tou_mat[30] = {1, 1, 9.9999996802856925e+37, 0, 0.094169996678829193, 0, 2, 1, 400, 0,
                                        0.096869997680187225, 0, 2, 2, 800, 0, 0.13817000389099121, 0, 2, 3, 3000, 0,
                                        0.16166999936103821, 0, 2, 4, 9.9999996802856925e+37, 0, 0.17257000505924225,
                                        0};
    ssc_data_set_matrix(data, "ur_ec_tou_mat", p_ur_ec_tou_mat, 5, 6);

    ssc_data_set_number(data, "inflation_rate", 2.5);
    ssc_number_t p_degradation[1] = {0};
    ssc_data_set_array(data, "degradation", p_degradation, 1);
    ssc_number_t p_load_escalation[1] = {0};
    ssc_data_set_array(data, "load_escalation", p_load_escalation, 1);
    ssc_number_t p_rate_escalation[1] = {0};
    ssc_data_set_array(data, "rate_escalation", p_rate_escalation, 1);
    ssc_data_set_number(data, "ur_metering_option", 2);
    ssc_data_set_number(data, "ur_nm_yearend_sell_rate", 0.027890000492334366);
    ssc_data_set_number(data, "ur_monthly_fixed_charge", 8.5500001907348633);
    ssc_data_set_number(data, "ur_monthly_min_charge", 0);
    ssc_data_set_number(data, "ur_annual_min_charge", 0);
    ssc_data_set_number(data, "ur_en_ts_sell_rate", 0);
    set_array(data, "ur_ts_sell_rate", generictest::sell_rate_unused, 8760);
    ssc_data_set_number(data, "ur_dc_enable", 1);
    ssc_number_t p_ur_dc_sched_weekday[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_dc_sched_weekday", p_ur_dc_sched_weekday, 12, 24);
    ssc_number_t p_ur_dc_sched_weekend[288] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    ssc_data_set_matrix(data, "ur_dc_sched_weekend", p_ur_dc_sched_weekend, 12, 24);
    ssc_number_t p_ur_dc_tou_mat[4] = {1, 1, 0, 0};
    ssc_data_set_matrix(data, "ur_dc_tou_mat", p_ur_dc_tou_mat, 1, 4);
    ssc_number_t p_ur_dc_flat_mat[48] = {0, 1, 0, 0, 1, 1, 0, 0, 2, 1, 0, 0, 3, 1, 0, 0, 4, 1, 0, 0, 5, 1, 0, 0, 6, 1,
                                         0, 0, 7, 1, 0, 0, 8, 1, 0, 0, 9, 1, 0, 0, 10, 1, 0, 0, 11, 1, 0, 0};
    ssc_data_set_matrix(data, "ur_dc_flat_mat", p_ur_dc_flat_mat, 12, 4);

    ssc_number_t p_federal_tax_rate[1] = {21};
    ssc_data_set_array(data, "federal_tax_rate", p_federal_tax_rate, 1);
    ssc_number_t p_state_tax_rate[1] = {7};
    ssc_data_set_array(data, "state_tax_rate", p_state_tax_rate, 1);
    ssc_data_set_number(data, "property_tax_rate", 0);
    ssc_data_set_number(data, "prop_tax_cost_assessed_percent", 100);
    ssc_data_set_number(data, "prop_tax_assessed_decline", 0);
    ssc_data_set_number(data, "real_discount_rate", 6.4000000953674316);
    ssc_data_set_number(data, "insurance_rate", 0.5);
    ssc_data_set_number(data, "loan_term", 25);
    ssc_data_set_number(data, "loan_rate", 7.5);
    ssc_data_set_number(data, "debt_fraction", 100);
    ssc_number_t p_om_fixed[1] = {0};
    ssc_data_set_array(data, "om_fixed", p_om_fixed, 1);
    ssc_data_set_number(data, "om_fixed_escal", 0);
    ssc_number_t p_om_production[1] = {0};
    ssc_data_set_array(data, "om_production", p_om_production, 1);
    ssc_data_set_number(data, "om_production_escal", 0);
    ssc_number_t p_om_capacity[1] = {25};
    ssc_data_set_array(data, "om_capacity", p_om_capacity, 1);
    ssc_data_set_number(data, "om_capacity_escal", 0);
    ssc_number_t p_om_fuel_cost[1] = {8};
    ssc_data_set_array(data, "om_fuel_cost", p_om_fuel_cost, 1);
    ssc_data_set_number(data, "om_fuel_cost_escal", 0);
    ssc_data_set_number(data, "depr_fed_type", 1);
    ssc_data_set_number(data, "depr_fed_sl_years", 7);
    ssc_number_t p_depr_fed_custom[1] = {0};
    ssc_data_set_array(data, "depr_fed_custom", p_depr_fed_custom, 1);
    ssc_data_set_number(data, "depr_sta_type", 1);
    ssc_data_set_number(data, "depr_sta_sl_years", 7);
    ssc_number_t p_depr_sta_custom[1] = {0};
    ssc_data_set_array(data, "depr_sta_custom", p_depr_sta_custom, 1);
    ssc_data_set_number(data, "itc_fed_amount", 0);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_fed", 1);
    ssc_data_set_number(data, "itc_fed_amount_deprbas_sta", 1);
    ssc_data_set_number(data, "itc_sta_amount", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_fed", 0);
    ssc_data_set_number(data, "itc_sta_amount_deprbas_sta", 0);
    ssc_data_set_number(data, "itc_fed_percent", 0);
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
    ssc_data_set_number(data, "battery_per_kWh", 300);
    ssc_data_set_number(data, "batt_replacement_cost_escal", 0);
    ssc_data_set_number(data, "total_installed_cost", 86827.921875);
    ssc_data_set_number(data, "salvage_percentage", 0);
}

#endif
