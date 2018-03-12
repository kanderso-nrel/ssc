#ifndef __SCO2_CYCLE_COMPONENTS_
#define __SCO2_CYCLE_COMPONENTS_

#include <vector>

#include "numeric_solvers.h"
#include "CO2_properties.h"

void calculate_turbomachinery_outlet_1(double T_in /*K*/, double P_in /*kPa*/, double P_out /*kPa*/, 
	double eta_isen /*-*/, bool is_comp, int & error_code, 
	double & enth_in /*kJ/kg*/, double & entr_in /*kJ/kg-K*/, double & dens_in /*kg/m3*/, double & temp_out /*K*/, 
	double & enth_out /*kJ/kg*/, double & entr_out /*kJ/kg-K*/, double & dens_out /*kg/m3*/, double & spec_work /*kJ/kg*/);

void calculate_turbomachinery_outlet_1(double T_in /*K*/, double P_in /*kPa*/, double P_out /*kPa*/, 
	double eta_isen /*-*/, bool is_comp, int & error_code, double & spec_work /*kJ/kg*/);

void isen_eta_from_poly_eta(double T_in /*K*/, double P_in /*kPa*/, double P_out /*kPa*/, double poly_eta /*-*/, bool is_comp, int & error_code, double & isen_eta);

int calc_turbomachinery_eta_isen(double T_in /*K*/, double P_in /*kPa*/,
	double T_out /*K*/, double P_out /*kPa*/, double & eta_isen);

int Ts_data_over_linear_dP_ds(double P_in /*kPa*/, double s_in /*kJ/kg-K*/, double P_out /*kPa*/, double s_out /*kJ/kg-K*/,
	std::vector<double> & T_data /*C*/, std::vector<double> & s_data /*kJ/kg-K*/, int N_points = 30);

int Ph_data_over_turbomachinery(double T_in /*K*/, double P_in /*kPa*/,
	double T_out /*K*/, double P_out /*kPa*/,
	std::vector<double> & P_data /*MPa*/, std::vector<double> & h_data /*kJ/kg*/, int N_points = 30);

int sco2_cycle_plot_data_TS(int cycle_config,
	const std::vector<double> pres /*kPa*/,
	const std::vector<double> entr /*kJ/kg-K*/,
	std::vector<double> & T_LTR_HP /*C*/,
	std::vector<double> & s_LTR_HP /*kJ/kg-K*/,
	std::vector<double> & T_HTR_HP /*C*/,
	std::vector<double> & s_HTR_HP /*kJ/kg-K*/,
	std::vector<double> & T_PHX	   /*C*/,
	std::vector<double> & s_PHX    /*kJ/kg-K*/,
	std::vector<double> & T_HTR_LP /*C*/,
	std::vector<double> & s_HTR_LP /*kJ/kg-K*/,
	std::vector<double> & T_LTR_LP /*C*/,
	std::vector<double> & s_LTR_LP /*kJ/kg-K*/,
	std::vector<double> & T_main_cooler /*C*/,
	std::vector<double> & s_main_cooler /*kJ/kg-K*/,
	std::vector<double> & T_pre_cooler /*C*/,
	std::vector<double> & s_pre_cooler /*kJ/kg-K*/);

int sco2_cycle_plot_data_PH(int cycle_config,
	const std::vector<double> temp /*K*/,
	const std::vector<double> pres /*kPa*/,
	std::vector<double> & P_t /*MPa*/,
	std::vector<double> & h_t /*kJ/kg*/,
	std::vector<double> & P_mc /*MPa*/,
	std::vector<double> & h_mc /*kJ/kg*/,
	std::vector<double> & P_rc /*MPa*/,
	std::vector<double> & h_rc /*kJ/kg*/,
	std::vector<double> & P_pc /*MPa*/,
	std::vector<double> & h_pc /*kJ/kg*/);

int Ts_arrays_over_constP(double T_cold /*C*/, double T_hot /*C*/, std::vector<double> P_consts /*kPa*/,
	std::vector<std::vector<double>> & T_data /*C*/, std::vector<std::vector<double>> & s_data);

int Ph_arrays_over_constT(double P_low /*MPa*/, double P_high /*MPa*/, std::vector<double> T_consts /*C*/,
	std::vector<std::vector<double>> & P_data /*MPa*/, std::vector<std::vector<double>> & h_data);

int Ts_dome(double T_cold /*C*/, std::vector<double> & T_data /*C*/, std::vector<double> & s_data);

int Ts_full_dome(double T_cold /*C*/, std::vector<double> & T_data /*C*/, std::vector<double> & s_data /*kJ/kg-K*/,
	std::vector<double> & P_data /*MPa*/, std::vector<double> & h_data /*kJ/kg*/);

int Ph_dome(double P_low /*MPa*/, std::vector<double> & P_data /*MPa*/, std::vector<double> & h_data);

class C_MEQ_CO2_props_at_2phase_P : public C_monotonic_equation
{
private:
	

public:
	C_MEQ_CO2_props_at_2phase_P(){}

	CO2_state mc_co2_props;

	virtual int operator()(double T_co2 /*K*/, double *P_calc /*kPa*/);
};

// Heat Exchanger Class
class C_HeatExchanger
{
public:
	struct S_design_parameters
	{
		int m_N_sub;							//[-] Number of sub-heat exchangers used in the model
		std::vector<double> m_m_dot_design;		//[kg/s] Design-point mass flow rates of the two streams
		std::vector<double> m_DP_design;		//[kPa] Design-point pressure drops across the heat exchanger
		double m_UA_design;						//[kW/K] Design-point conductance
		double m_Q_dot_design;					//[kW] Design-point heat transfer
		double m_min_DT_design;					//[K] Minimum temperature difference in heat exchanger
		double m_eff_design;					//[-] Effectiveness at design

		S_design_parameters()
		{
			m_N_sub = -1;

			m_m_dot_design.resize(2);
			std::fill(m_m_dot_design.begin(), m_m_dot_design.end(), std::numeric_limits<double>::quiet_NaN());
			m_DP_design.resize(2);
			std::fill(m_DP_design.begin(), m_DP_design.end(), std::numeric_limits<double>::quiet_NaN());

			m_UA_design = m_Q_dot_design = m_min_DT_design = m_eff_design = std::numeric_limits<double>::quiet_NaN();
		}
	};

private:
	S_design_parameters ms_des_par;

public:
	~C_HeatExchanger(){};

	C_HeatExchanger(){};

	void initialize(const S_design_parameters & des_par_in);

	// Performance Methods:
	// *Some check to ensure member structures are initialized?*
	void hxr_pressure_drops(const std::vector<double> & m_dots, std::vector<double> & hxr_deltaP);

	void hxr_conductance(const std::vector<double> & m_dots, double & hxr_UA);

};

class C_turbine
{
public:
	struct S_design_parameters
	{
		double m_N_design;					//[rpm] turbine shaft speed
		double m_N_comp_design_if_linked;	//[rpm] compressor shaft speed
		// Turbine inlet state
		double m_P_in;						//[kPa]
		double m_T_in;						//[K] 
		double m_D_in;						//[kg/m^3] 
		double m_h_in;						//[kJ/kg]
		double m_s_in;						//[kJ/kg-K]
		// Turbine outlet state
		double m_P_out;						//[kPa]
		double m_h_out;						//[kJ/kg]
		// Mass flow rate
		double m_m_dot;						//[kg/s]

		S_design_parameters()
		{
			m_N_design = m_N_comp_design_if_linked =
				m_P_in = m_T_in = m_D_in = m_h_in = m_s_in = m_P_out = m_h_out =
				m_m_dot = std::numeric_limits<double>::quiet_NaN();
		}
	};

	struct S_design_solved
	{
		double m_nu_design;					//[-] ratio of tip speed to spouting velocity
		double m_D_rotor;					//[m] Turbine diameter
		double m_A_nozzle;					//[m^2] Effective nozzle area
		double m_w_tip_ratio;				//[-] ratio of tip speed to local speed of sound
		double m_eta;						//[-] 
		double m_N_design;					//[rpm] shaft speed

		S_design_solved()
		{
			m_nu_design = m_D_rotor = m_A_nozzle = m_w_tip_ratio = m_eta = m_N_design = std::numeric_limits<double>::quiet_NaN();
		}
	};

	struct S_od_solved
	{
		double m_nu;						//[-] ratio of tip speed to spouting velocity
		double m_eta;						//[-] turbine efficiency
		double m_w_tip_ratio;				//[-] ratio of the tip speed to the local (turbine inlet) speed of sound
		double m_N;							//[rpm] off-design turbine shaft speed

		double m_W_dot_out;			//[kW] Turbine power output, expected to be positive

		S_od_solved()
		{
			m_nu = m_eta = m_w_tip_ratio = m_N =
				m_W_dot_out = std::numeric_limits<double>::quiet_NaN();
		}
	};

private:
	S_design_parameters ms_des_par;
	S_design_solved ms_des_solved;
	S_od_solved ms_od_solved;

public:
	~C_turbine(){};

	C_turbine(){};

	static const double m_nu_design;

	const S_design_solved * get_design_solved()
	{
		return &ms_des_solved;
	}

	const S_od_solved * get_od_solved()
	{
		return &ms_od_solved;
	}

	void turbine_sizing(const S_design_parameters & des_par_in, int & error_code);

	void off_design_turbine(double T_in, double P_in, double P_out, double N, int & error_code, double & m_dot, double & T_out);

	void od_turbine_at_N_des(double T_in, double P_in, double P_out, int & error_code, double & m_dot, double & T_out);
};

class C_comp_single_stage
{
public:

	struct S_des_solved
	{
		// Compressor inlet conditions
		double m_T_in;			//[K]
		double m_P_in;			//[kPa]
		double m_D_in;			//[kg/m^3]
		double m_h_in;			//[kJ/kg]
		double m_s_in;			//[kJ/kg-K]
		// Compressor outlet conditions
		double m_T_out;			//[K]
		double m_P_out;			//[kPa]
		double m_h_out;			//[kJ/kg]
		double m_D_out;			//[kg/m^3]
		// Mass flow
		double m_m_dot;			//[kg/s]

		// Geometry
		double m_D_rotor;		//[m]
		double m_N_design;		//[rpm]
		double m_tip_ratio;		//[-]
		double m_eta_design;	//[-]

		double m_phi_des;		//[-]
		double m_phi_surge;		//[-]
		double m_phi_max;		//[-]

		S_des_solved()
		{
			m_T_in = m_P_in = m_D_in = m_h_in = m_s_in =
				m_T_out = m_P_out = m_h_out = m_D_out =
				m_m_dot = m_D_rotor = m_N_design = m_tip_ratio = m_eta_design =
				m_phi_surge = m_phi_des = m_phi_max = std::numeric_limits<double>::quiet_NaN();
		}
	};

	struct S_od_solved
	{
		double m_P_in;			//[kPa] Inlet pressure
		double m_h_in;			//[kJ/kg] Inlet enthalpy
		double m_T_in;			//[K] Inlet temperature
		double m_s_in;			//[kJ/kg-K] Inlet entropy

		double m_P_out;			//[kPa] Outlet pressure
		double m_h_out;			//[kPa] Outlet enthalpy
		double m_T_out;			//[K] Outlet temperature
		double m_s_out;			//[kJ/kg-K] Outlet entropy


		bool m_surge;			//[-]
		double m_eta;			//[-]
		double m_phi;			//[-]
		double m_w_tip_ratio;	//[-]

		double m_N;			//[rpm]

		double m_W_dot_in;		//[KWe] Power required by compressor, positive value expected
		double m_surge_safety;	//[-] Flow coefficient / min flow coefficient

		S_od_solved()
		{
			m_P_in = m_h_in = m_T_in = m_s_in =
				m_P_out = m_h_out = m_T_out = m_s_out = std::numeric_limits<double>::quiet_NaN();
			m_surge = false;
			m_eta = m_phi = m_w_tip_ratio = m_N =
				m_W_dot_in = m_surge_safety = std::numeric_limits<double>::quiet_NaN();
		}
	};

	S_des_solved ms_des_solved;
	S_od_solved ms_od_solved;

	~C_comp_single_stage(){};

	C_comp_single_stage(){};

	static const double m_snl_phi_design;		//[-] Design-point flow coef. for Sandia compressor (corresponds to max eta)
	static const double m_snl_phi_min;				//[-] Approximate surge limit for SNL compressor
	static const double m_snl_phi_max;				//[-] Approximate x-intercept for SNL compressor

	const S_des_solved * get_design_solved()
	{
		return &ms_des_solved;
	}

	int design_given_shaft_speed(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/,
		double N_rpm /*rpm*/, double eta_isen /*-*/, double & P_out /*kPa*/, double & T_out /*K*/, double & tip_ratio /*-*/);

	int design_single_stage_comp(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/,
		double T_out /*K*/, double P_out /*K*/);

	int off_design_given_N(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/, double N_rpm /*rpm*/,
		double & T_out /*K*/, double & P_out /*kPa*/);

	int calc_N_from_phi(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/, double phi_in /*-*/, double & N_rpm /*rpm*/);
};

class C_comp_multi_stage
{
public:

	std::vector<C_comp_single_stage> mv_stages;

	struct S_des_solved
	{
		// Compressor inlet conditions
		double m_T_in;			//[K]
		double m_P_in;			//[kPa]
		double m_D_in;			//[kg/m^3]
		double m_h_in;			//[kJ/kg]
		double m_s_in;			//[kJ/kg-K]
		// Compressor outlet conditions
		double m_T_out;			//[K]
		double m_P_out;			//[kPa]
		double m_h_out;			//[kJ/kg]
		double m_D_out;			//[kg/m^3]
		// Mass flow
		double m_m_dot;			//[kg/s]

		// Geometry
		double m_N_design;		//[rpm]
		double m_phi_des;		//[-]
		double m_w_tip_ratio;	//[-] Max tip ratio over all stages
		int m_n_stages;			//[-] Number of stages
		double m_D_rotor;		//[m] First stage rotor diameter
		double m_phi_surge;		//[-] Flow coefficient at surge

		S_des_solved()
		{
			m_n_stages = -1;

			m_T_in = m_P_in = m_D_in = m_h_in = m_s_in =
				m_T_out = m_P_out = m_h_out = m_D_out =
				m_m_dot =
				m_N_design = m_phi_des = m_w_tip_ratio = std::numeric_limits<double>::quiet_NaN();
		}
	};

	struct S_od_solved
	{
		double m_P_in;			//[kPa] Inlet pressure
		double m_T_in;			//[K] Inlet temperature

		double m_P_out;			//[kPa] Outlet pressure
		double m_T_out;			//[K] Outlet temperature

		bool m_surge;			//[-]
		double m_eta;			//[-]
		double m_phi;			//[-] Min phi over all stages
		double m_w_tip_ratio;	//[-] Max tip ratio over all stages

		double m_N;			//[rpm]

		double m_W_dot_in;		//[KWe] Power required by compressor, positive value expected
		double m_surge_safety;	//[-] Flow coefficient / min flow coefficient

		S_od_solved()
		{
			m_P_in = m_T_in =
				m_P_out = m_T_out = std::numeric_limits<double>::quiet_NaN();

			m_surge = false;
			m_eta = m_phi = m_w_tip_ratio = m_N =
				m_W_dot_in = m_surge_safety = std::numeric_limits<double>::quiet_NaN();
		}
	};

	S_des_solved ms_des_solved;
	S_od_solved ms_od_solved;

	~C_comp_multi_stage(){};

	C_comp_multi_stage(){};

	const S_des_solved * get_design_solved()
	{
		return &ms_des_solved;
	}

	const S_od_solved * get_od_solved()
	{
		return &ms_od_solved;
	}

	class C_MEQ_eta_isen__h_out : public C_monotonic_equation
	{
	private:
		C_comp_multi_stage *mpc_multi_stage;
		double m_T_in;	//[K]
		double m_P_in;	//[kPa]
		double m_P_out;	//[kPa]
		double m_m_dot;	//[kg/s]

	public:
		C_MEQ_eta_isen__h_out(C_comp_multi_stage *pc_multi_stage,
			double T_in /*K*/, double P_in /*kPa*/, double P_out /*kPa*/, double m_dot /*kg/s*/)
		{
			mpc_multi_stage = pc_multi_stage;
			m_T_in = T_in;
			m_P_in = P_in;
			m_P_out = P_out;
			m_m_dot = m_dot;
		}

		virtual int operator()(double eta_isen /*-*/, double *h_comp_out /*kJ/kg*/);
	};

	class C_MEQ_N_rpm__P_out : public C_monotonic_equation
	{
	private:
		C_comp_multi_stage *mpc_multi_stage;
		double m_T_in;	//[K]
		double m_P_in;	//[kPa]
		double m_m_dot;	//[kg/s]
		double m_eta_isen;	//[-]

	public:
		C_MEQ_N_rpm__P_out(C_comp_multi_stage *pc_multi_stage,
			double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/, double eta_isen /*-*/)
		{
			mpc_multi_stage = pc_multi_stage;
			m_T_in = T_in;	//[K]
			m_P_in = P_in;	//[kPa]
			m_m_dot = m_dot;	//[kg/s]
			m_eta_isen = eta_isen;	//[-]
		}

		virtual int operator()(double N_rpm /*rpm*/, double *P_comp_out /*kPa*/);
	};

	class C_MEQ_phi_od__P_out : public C_monotonic_equation
	{
	private:
		C_comp_multi_stage *mpc_multi_stage;
		double m_T_in;	//[K]
		double m_P_in;	//[kPa]
		double m_m_dot;	//[kg/s]

	public:
		C_MEQ_phi_od__P_out(C_comp_multi_stage *pc_multi_stage,
			double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/)
		{
			mpc_multi_stage = pc_multi_stage;
			m_T_in = T_in;		//[K]
			m_P_in = P_in;		//[kPa]
			m_m_dot = m_dot;	//[kg/s]
		}

		virtual int operator()(double phi_od /*-*/, double *P_comp_out /*kPa*/);
	};

	int design_given_outlet_state(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/,
		double T_out /*K*/, double P_out /*K*/);

	void off_design_given_N(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/, double N_rpm /*rpm*/,
		int & error_code, double & T_out /*K*/, double & P_out /*kPa*/);

	void off_design_at_N_des(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/,
		int & error_code, double & T_out /*K*/, double & P_out /*kPa*/);

	void off_design_given_P_out(double T_in /*K*/, double P_in /*kPa*/, double m_dot /*kg/s*/,
		double P_out /*kPa*/, int & error_code, double & T_out /*K*/);

};


#endif