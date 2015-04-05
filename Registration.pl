#!/usr/local/bin/perl -wT
use strict; 
use CGI ':standard';

$name = param('fullname');
$username = param('username');
$password = param('passwd');

print "Content-type: text/html\n\n";

sub main{
open (LOG, "<members.csv") || Error('open','file');
my $existing = 0;
my $line = <LOG>;
while($line = <LOG>){
	my @data = split(' ', $line);
	if($data[0] eq $name){
		$existing = 1;
	}
}
close(LOG);
if($existing == 0){
	open (LOG, ">>members.csv") || Error('open','file');
	print LOG "$name $username $password\n";
	close(LOG);
}
else{
	print "Error: Username already exists";
	print "Location: "
}

}
