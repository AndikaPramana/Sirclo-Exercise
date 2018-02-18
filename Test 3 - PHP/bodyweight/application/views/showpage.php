<?php include "header.php"; ?>
<table border="1" cellpadding="5">
      <tr>
        <th>Date</th>
        <th><?php echo $bodyrecord->Date ?></th>
      </tr>
      <tr>
      	<td>Max</td>
      	<td><?php echo $bodyrecord->Max ?></td>
      </tr>
      <tr>
      	<td>Min</td>
      	<td><?php echo $bodyrecord->Min ?></td>
      </tr>
      <tr>
      	<td>Variance</td>
      	<td><?php echo $bodyrecord->Variance ?></td>
      </tr>
    </table>
<?php include "footer.php"; ?>