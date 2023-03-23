
#
# 123
# 456
# 789
#

my @lines = ([1,2,3], [4,5,6], [7,8,9],
             [1,4,7], [2,5,8], [3,6,9],
             [1,5,9], [3,5,7],
            );

my @todo = (["x", (".") x 9]);

my %seen;

my $TOTAL_STATES = 0;
my $END_STATES = 0;
while (@todo) {
  my $pos = shift @todo;
  printf " %s | %s | %s\n---+---+---\n %s | %s | %s\n---+---+---\n %s | %s | %s\n\n",
    @{$pos}[1..9];
  next if $seen{join "", @$pos}++; # saw this position already
  $TOTAL_STATES += 1;
  my @children = next_moves($pos);
  $END_STATES += 1 if @children == 0;
  push @todo, @children;
}

printf "Total positions: %d\nTerminal positions: %d\n",
  $TOTAL_STATES, $END_STATES;

sub next_moves {
  my ($position) = @_;
  return if game_over($position);

  my $to_move = $position->[0];
  my $next_to_move = ($to_move eq "x" ? "o" : "x");

  my @new_positions;
  for my $space (1 .. 9) {
    next unless $position->[$space] eq ".";
    my @new_position = @$position;
    $new_position[$space] = $to_move;
    $new_position[0]      = $next_to_move;
    push @new_positions, \@new_position;
  }
  return @new_positions;
}

sub game_over {
  my ($move) = @_;
  for my $line (@lines) {
    return 1 if 
      $move->[$line->[0]] ne "." &&
      $move->[$line->[0]] eq $move->[$line->[1]] &&
      $move->[$line->[0]] eq $move->[$line->[2]];
  }
  return;
}
