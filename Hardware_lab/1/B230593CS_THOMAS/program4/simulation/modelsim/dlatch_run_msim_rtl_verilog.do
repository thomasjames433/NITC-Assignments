transcript on
if {[file exists rtl_work]} {
	vdel -lib rtl_work -all
}
vlib rtl_work
vmap work rtl_work

vlog -vlog01compat -work work +incdir+C:/AA\ AAAAA/NITC/Sem3/Hardware\ lab/b230593cs/program4 {C:/AA AAAAA/NITC/Sem3/Hardware lab/b230593cs/program4/dlatch.v}
vlog -vlog01compat -work work +incdir+C:/AA\ AAAAA/NITC/Sem3/Hardware\ lab/b230593cs/program4 {C:/AA AAAAA/NITC/Sem3/Hardware lab/b230593cs/program4/dlatch8.v}

vlog -vlog01compat -work work +incdir+C:/AA\ AAAAA/NITC/Sem3/Hardware\ lab/b230593cs/program4 {C:/AA AAAAA/NITC/Sem3/Hardware lab/b230593cs/program4/dlatch_tb.v}

vsim -t 1ps -L altera_ver -L lpm_ver -L sgate_ver -L altera_mf_ver -L altera_lnsim_ver -L fiftyfivenm_ver -L rtl_work -L work -voptargs="+acc"  dlatch_tb

add wave *
view structure
view signals
run -all
