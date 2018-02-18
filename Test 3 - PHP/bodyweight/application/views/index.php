<?php include "header.php"; 

// display link to add record
echo "<a href='".base_url("index.php/BodyWeightController/create/")."'>Add Daily Data</a><br><br>";
?>

<table border="1" cellpadding="5">
      <tr>
        <th>Date</th>
        <th>Max</th>
        <th>Min</th>
        <th>Variance</th>
       <th colspan="3">Option</th> 
      </tr>
<?php
     
      if( ! empty($bodyrecord)){ // check if table is empty, if not, then display the data
        
        // loop through each row to display result
        foreach($bodyrecord->result() as $data){

          // add max min and variance to array to calculate the average later
          $maxdata[] = $data->Max;
          $mindata[] = $data->Min;
          $vardata[] = $data->Variance;

          echo "<tr>
          <td>".$data->Date."</td>
          <td>".$data->Max."</td>
          <td>".$data->Min."</td>
          <td>".$data->Variance."</td>
          <td><a href='".base_url("index.php/BodyWeightController/show/".$data->Date)."'>Show</a></td>
          <td><a href='".base_url("index.php/BodyWeightController/update/".$data->Date)."'>Edit</a></td>
          <td><a href='".base_url("index.php/BodyWeightController/delete/".$data->Date)."'>Delete</a></td>
          </tr>";

        }

        // calculate the average
        $avgmax = array_sum($maxdata) / sizeof($maxdata);
        $avgmin = array_sum($mindata) / sizeof($mindata);
        $avgvar = array_sum($vardata) / sizeof($vardata);

        echo "<tr>
        <td>"."Average"."</td>
        <td>".$avgmax."</td>
        <td>".$avgmin."</td>
        <td>".$avgvar."</td>
        <td colspan='3'></td>
        </tr>";

      }else{ // if there's no data then display the message
        echo "<tr><td align='center' colspan='7'>There is no data</td></tr>";
      }
      ?>
    </table>
<?php include "footer.php"; ?>