S=nmcli d | grep ppp

if [S];then
	nmcli c down bd222d63-c6bb-4d51-a4d4-aa1c9a0de139
else if[S==0]
	nmcli c up bd222d63-c6bb-4d51-a4d4-aa1c9a0de139
fi